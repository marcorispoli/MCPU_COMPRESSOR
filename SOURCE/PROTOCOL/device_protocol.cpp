#include "application.h"
#include "can_device_protocol.h"

deviceProtocol::deviceProtocol(void):canDeviceProtocol(Application::DEVICE_ID, Application::IP_CAN_ADDRESS, Application::CAN_PORT)
{
    workflow = _WORKFLOW_INITIALIZATION;
    subWorkflow = 0;
    QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));

    canDeviceProtocolFrame::CAN_REGISTER_t reg0;
    reg0.d[0] = 0;
    reg0.d[1] = 0;
    reg0.d[2] = 0;
    reg0.d[3] = 0;

    // Creates the register structure
    for(int i=0; i< STATUS_LEN; i++) statusRegisters.append(reg0);
    for(int i=0; i< DATA_LEN; i++) dataRegisters.append(reg0);
    for(int i=0; i< PARAMETER_LEN; i++) paramRegisters.append(reg0);


    execCmd = 0;
    abortCmd = false;
}


/**
 * @brief Board initialization process
 *
 * The Initialization workflow executes the following jobs:
 * + Reads the configuration file to get the board parameter configuration
 * + Requests the current revision to the Device
 * + Read the Device parameters
 * + Upgrade and store the device parameters
 */
void deviceProtocol::workflowINITIALIZATION(void){
    static uint8_t idx;
    bool ris;
    static bool store_parameters_requested;

    // Waiting for the answer
    if(isCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowINITIALIZATION()));
        return;
    }

    switch(subWorkflow){

        case 0:
            store_parameters_requested = false;

            if(!accessRegister(canDeviceProtocolFrame::READ_REVISION)){
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowINITIALIZATION()));
            return;

        case 1:
            if(!isCommunicationOk()){
                qDebug() << "REVISION FRAME TIMEOUT: " << getFrameErrorStr();
                subWorkflow = 0;
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            qDebug() << "DEVICE REVISION: " << (uchar) revisionRegister.d[0] << "." <<  revisionRegister.d[1] << "." << revisionRegister.d[2];
            subWorkflow = 2;
            QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));

            idx = 0;
            break;

        case 2: // Read the parameters
            if(idx >= PARAMETER_LEN){
                // Configuration read complted
                subWorkflow = 4;
                QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            if(!accessRegister(canDeviceProtocolFrame::READ_PARAM,idx)){
                qDebug() << "err0";
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowINITIALIZATION()));
            return;

        case 3:

            if(!isCommunicationOk()){
                qDebug() << "err1";
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }
            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            break;

        case 4:
            if(WINDOW) WINDOW->updateParameters();
            qDebug() << "Upload Parameter completed";

            // Verifies if there are different values
            if(
                (paramRegisters[0].d[0] != CONFIG->getParam<uchar>(PARAM_0,0)) ||
                (paramRegisters[1].d[0] != CONFIG->getParam<uchar>(PARAM_1,0)) ||
                (paramRegisters[2].d[0] != CONFIG->getParam<uchar>(PARAM_2,0)) ||
                (paramRegisters[3].d[0] != CONFIG->getParam<uchar>(PARAM_3,0)) ||
                (paramRegisters[4].d[0] != CONFIG->getParam<uchar>(PARAM_4,0)) ||
                (paramRegisters[4].d[1] != CONFIG->getParam<uchar>(PARAM_4,1)) ||
                (paramRegisters[5].d[0] != CONFIG->getParam<uchar>(PARAM_5,0)) ||
                (paramRegisters[5].d[1] != CONFIG->getParam<uchar>(PARAM_5,1)) ||
                (paramRegisters[6].d[0] != CONFIG->getParam<uchar>(PARAM_6,0)) ||
                (paramRegisters[6].d[1] != CONFIG->getParam<uchar>(PARAM_6,1)) ||
                (paramRegisters[7].d[0] != CONFIG->getParam<uchar>(PARAM_7,0)) ||
                (paramRegisters[7].d[1] != CONFIG->getParam<uchar>(PARAM_7,1)) ||
                (paramRegisters[8].d[0] != CONFIG->getParam<uchar>(PARAM_8,0)) ||
                (paramRegisters[8].d[1] != CONFIG->getParam<uchar>(PARAM_8,1))
                ){
                    store_parameters_requested = true;
                    subWorkflow++;
                    idx = 0;
                    qDebug() << "DATA CHANGED";
                    QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
                    break;
            }

            // Test if the STore Cmmmand is requested
            if(store_parameters_requested) subWorkflow = 7;
            else subWorkflow = 10;

            QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));

            break;

        case 5: // Write the parameters
            if(idx >= PARAMETER_LEN){
                // Re-read again to be sure
                subWorkflow = 2;
                idx = 0;
                QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
                return;
            }
            if(idx == 0) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_0,0));
            else if(idx == 1) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_1,0));
            else if(idx == 2) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_2,0));
            else if(idx == 3) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_3,0));
            else if(idx == 4) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_4,0), CONFIG->getParam<uchar>(PARAM_4,1));
            else if(idx == 5) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_5,0), CONFIG->getParam<uchar>(PARAM_5,1));
            else if(idx == 6) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_6,0), CONFIG->getParam<uchar>(PARAM_6,1));
            else if(idx == 7) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_7,0), CONFIG->getParam<uchar>(PARAM_7,1));
            else if(idx == 8) ris = accessRegister(canDeviceProtocolFrame::WRITE_PARAM,idx,CONFIG->getParam<uchar>(PARAM_8,0), CONFIG->getParam<uchar>(PARAM_8,1));
            else ris = false;

            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowINITIALIZATION()));
            return;

        case 6:
            if(!isCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            break;

        case 7: // Store parameter command
            if(!accessRegister(canDeviceProtocolFrame::STORE_PARAMS,0)){
                qDebug() << "STORE COMMAND NOT EXECUTED";
                subWorkflow = 10;
                QTimer::singleShot(1,this, SLOT(workflowINITIALIZATION()));
                break;
            }

            qDebug() << "PARAMETER STORING ..";
            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            break;

        case 8:
            if(!isCommunicationOk()){
                qDebug() << "STORE COMMAND FAILED";
            }else qDebug() << "PARAMETER SUCCESSFULLY STORED";

            subWorkflow = 10;
            idx = 0;
            QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
            qDebug() << "WRITE DATA REGISTERS";
            break;

        case 10: // DATA register update
            if(idx >= DATA_LEN){
                qDebug() << "DATA REGISTERS SUCCESSFULLY WRITTEN";
                if(WINDOW) WINDOW->updateData();
                subWorkflow =  12;
                idx = 0;
                QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            ris = accessRegister(canDeviceProtocolFrame::WRITE_DATA,idx,dataRegisters[idx].d[0],dataRegisters[idx].d[1],dataRegisters[idx].d[2],dataRegisters[idx].d[3]);
            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            return;

        case 11:
            if(!isCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            break;

        case 12: // STATUS register update
            if(idx >= STATUS_LEN){
                qDebug() << "STATUS REGISTERS SUCCESSFULLY WRITTEN";
                if(WINDOW) WINDOW->updateStatus();
                subWorkflow =  14;
                idx = 0;
                QTimer::singleShot(0,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            ris = accessRegister(canDeviceProtocolFrame::READ_STATUS,idx);
            if(!ris){
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            return;

        case 13:
            if(!isCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
                return;
            }

            idx++;
            subWorkflow--;
            QTimer::singleShot(100,this, SLOT(workflowINITIALIZATION()));
            break;

        case 14:
            subWorkflow =  0;
            qDebug() << "WORKFLOW INITIALIZATION COMPLETED";
            QTimer::singleShot(100,this, SLOT(workflowIDLE()));
            return;



    }
}

void deviceProtocol::workflowIDLE(void){
    bool ris;
    static uchar status_count = 100;

    // Waiting for the answer
    if(isCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowIDLE()));
        return;
    }

    switch(subWorkflow){
        case 0:
            qDebug() << "WORKFLOW IDLE ACTIVATION";
            subWorkflow++;
            QTimer::singleShot(50,this, SLOT(workflowIDLE()));
        break;

        case 1: // SYSTEM STATUS register update
            if(!status_count){
                ris = accessRegister(canDeviceProtocolFrame::READ_STATUS,STATUS_BATTERY);
            }else  ris = accessRegister(canDeviceProtocolFrame::READ_STATUS,STATUS_SYSTEM);

            if(!ris){
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 2:
            if(!isCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }
            if(WINDOW) WINDOW->updateStatus();

            if(!status_count) status_count = 100;
            else status_count--;

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 3: // DATA REGISTER UPGRADE
            if(WINDOW) WINDOW->assignData();

            ris = accessRegister(canDeviceProtocolFrame::WRITE_DATA,DATA_OUTPUTS,dataRegisters[DATA_OUTPUTS].d[0],dataRegisters[DATA_OUTPUTS].d[1],dataRegisters[DATA_OUTPUTS].d[2],dataRegisters[DATA_OUTPUTS].d[3]);
            if(!ris){
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 4:
            if(!isCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }

            // Verifies if a command execution has been requested
            if((abortCmd) || (execCmd)) subWorkflow = 100;
            else subWorkflow = 1;

            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 100:
            commandRegister.valid = false;
            if(abortCmd){
                abortCmd = false;
                if(!abortCommand()){
                    qDebug() << "ABORT COMMAND NOT EXECUTED";
                    subWorkflow = 1;
                    QTimer::singleShot(11,this, SLOT(workflowINITIALIZATION()));
                    return;
                }
            }else if(!accessRegister(canDeviceProtocolFrame::COMMAND_EXEC,execCmd,execParam[0],execParam[1],execParam[2],execParam[3])){
                qDebug() << "COMMAND NOT EXECUTED";
                execCmd = 0;
                subWorkflow = 1;
                QTimer::singleShot(1,this, SLOT(workflowIDLE()));
                return;
            }

            execCmd = 0;
            subWorkflow++;
            QTimer::singleShot(1,this, SLOT(workflowIDLE()));
            return;

        case 101:
            if(!isCommunicationOk()){
                qDebug() << "COMMAND FRAME TIMEOUT";
                subWorkflow = 1;
                QTimer::singleShot(1,this, SLOT(workflowIDLE()));
                return;
            }

            switch(commandRegister.status){
                case canDeviceProtocolFrame::CAN_COMMAND_EXECUTING:
                    subWorkflow = 102;
                    QTimer::singleShot(100,this, SLOT(workflowIDLE()));
                    return;
                case canDeviceProtocolFrame::CAN_COMMAND_ERROR:
                    qDebug() << "COMMAND:" << commandRegister.command <<  "- ERRCODE: " <<  canDeviceProtocolFrame::getCommandErrorStr(commandRegister.error);
                    subWorkflow = 1;
                    QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                    return;

                case canDeviceProtocolFrame::CAN_COMMAND_EXECUTED:
                    qDebug() << "COMMAND:" << commandRegister.command << "COMPLETED. B0:" << commandRegister.b0 << ", B1:" << commandRegister.b1;
                    subWorkflow = 1;
                    QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                    return;
            }

            break;

        case 102:
            if(!accessRegister(canDeviceProtocolFrame::READ_COMMAND)){
                qDebug() << "READ COMMAND REGISTER ACCESS FAILED!";
                subWorkflow = 1;
                QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow = 101;
            QTimer::singleShot(1,this, SLOT(workflowINITIALIZATION()));
            return;

    }

    QTimer::singleShot(0,this, SLOT(workflowIDLE()));
}

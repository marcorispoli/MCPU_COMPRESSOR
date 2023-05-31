#include "application.h"
#include "can_device_protocol.h"

typedef enum{
    _WI_0 ,

}_WorflowIdleSteps;


void deviceProtocol::workflowIDLE(void){
    bool ris;
    static uchar status_count = 0;
    workflow = _WORKFLOW_IDLE;

    // Waiting for the answer
    if(isDeviceCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowIDLE()));
        return;
    }

    if(execCmd == ACTIVATE_BOOTLOADER){
        subWorkflow =  0;
        qDebug() << "BOOTLOADER INITIALIZATION..";
        QTimer::singleShot(0,this, SLOT(workflowBOOTLOADER()));
        return;
    }

    switch(subWorkflow){
        case 0:
            qDebug() << "WORKFLOW IDLE ACTIVATION";
            subWorkflow++;
            QTimer::singleShot(50,this, SLOT(workflowIDLE()));
        break;

        case 1: // SYSTEM STATUS register update
            switch(status_count){
                case 0:ris = deviceAccessRegister(canDeviceProtocolFrame::READ_STATUS,STATUS_SYSTEM);break;

            }


            if(!ris){
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 2:
            if(!isDeviceCommunicationOk()){
                subWorkflow --;
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }
            if(WINDOW) WINDOW->updateStatus();

            status_count++;
            if(status_count == 3) status_count = 0;

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 3: // DATA REGISTER UPGRADE
            if(WINDOW) WINDOW->assignData();

            ris = deviceAccessRegister(canDeviceProtocolFrame::WRITE_DATA,DATA_OUTPUTS,deviceDataRegisters[DATA_OUTPUTS].d[0],deviceDataRegisters[DATA_OUTPUTS].d[1],deviceDataRegisters[DATA_OUTPUTS].d[2],deviceDataRegisters[DATA_OUTPUTS].d[3]);
            if(!ris){
                QTimer::singleShot(50,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowIDLE()));
            return;

        case 4:
            if(!isDeviceCommunicationOk()){
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
            deviceCommandRegister.valid = false;
            if(abortCmd){
                abortCmd = false;
                if(!deviceAbortCommand()){
                    qDebug() << "ABORT COMMAND NOT EXECUTED";
                    subWorkflow = 1;
                    QTimer::singleShot(11,this, SLOT(workflowIDLE()));
                    return;
                }

            }else if(!deviceAccessRegister(canDeviceProtocolFrame::COMMAND_EXEC,execCmd,execParam[0],execParam[1],execParam[2],execParam[3])){
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
            if(!isDeviceCommunicationOk()){
                qDebug() << "COMMAND FRAME TIMEOUT";
                subWorkflow = 1;
                QTimer::singleShot(1,this, SLOT(workflowIDLE()));
                return;
            }

            switch(deviceCommandRegister.status){
                case canDeviceProtocolFrame::CAN_COMMAND_EXECUTING:
                    qDebug() << "COMMAND EXECUTING";
                    subWorkflow = 102;
                    QTimer::singleShot(100,this, SLOT(workflowIDLE()));
                    return;
                case canDeviceProtocolFrame::CAN_COMMAND_ERROR:
                    qDebug() << "COMMAND:" << deviceCommandRegister.command <<  "- ERRCODE: " <<  canDeviceProtocolFrame::getCommandErrorStr(deviceCommandRegister.error);
                    subWorkflow = 1;
                    QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                    return;

                case canDeviceProtocolFrame::CAN_COMMAND_EXECUTED:
                    qDebug() << "COMMAND:" << deviceCommandRegister.command << "COMPLETED. B0:" << deviceCommandRegister.b0 << ", B1:" << deviceCommandRegister.b1;
                    subWorkflow = 1;
                    QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                    return;
            }

            break;

        case 102:

            if(abortCmd){
                subWorkflow = 100;
                QTimer::singleShot(0,this, SLOT(workflowIDLE()));
                return;
            }

            if(!deviceAccessRegister(canDeviceProtocolFrame::READ_COMMAND)){
                qDebug() << "READ COMMAND REGISTER ACCESS FAILED!";
                subWorkflow = 1;
                QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                return;
            }

            subWorkflow = 101;
            QTimer::singleShot(1,this, SLOT(workflowIDLE()));
            return;

    }

    QTimer::singleShot(0,this, SLOT(workflowIDLE()));
}

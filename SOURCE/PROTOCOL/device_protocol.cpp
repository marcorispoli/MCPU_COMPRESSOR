#include "application.h"
#include "can_device_protocol.h"


deviceProtocol::deviceProtocol(void):canDeviceProtocol(Application::DEVICE_ID, SYSCONFIG->getParam<QString>(SYS_CAN_PROCESS_PARAM, SYS_PROCESS_IP) ,  SYSCONFIG->getParam<uint>(SYS_CAN_PROCESS_PARAM, SYS_PROCESS_PORT))
{

    canDeviceProtocolFrame::CAN_REGISTER_t reg0;
    reg0.d[0] = 0;
    reg0.d[1] = 0;
    reg0.d[2] = 0;
    reg0.d[3] = 0;

    // Creates the register structure
    for(int i=0; i< STATUS_LEN; i++) deviceStatusRegisters.append(reg0);
    for(int i=0; i< DATA_LEN; i++) deviceDataRegisters.append(reg0);
    for(int i=0; i< PARAMETER_LEN; i++) deviceParamRegisters.append(reg0);


    execCmd = 0;
    abortCmd = false;
    workflow = _WORKFLOW_NONE;
    board_initialized = false;
}

typedef enum{
    _WI_BOOTINIT_START = 0,
    _WI_WAIT_CAN_CONNECTION_0,
    _WI_WAIT_CAN_CONNECTION_1,
    _WI_GET_INFO_REQ_0,
    _WI_GET_INFO_REQ_1,
    _WI_BOOTINIT_COMPLETED,
}_WorflowBootInitSteps;

void deviceProtocol::boardInitialize(void){
    if(workflow == _WORKFLOW_BOOTINIT) return; // Is already initializing
    board_initialized = false;
    subWorkflow = _WI_BOOTINIT_START;
    QTimer::singleShot(100,this, SLOT(workflowBOOTINIT()));
    return;
}

void deviceProtocol::workflowBOOTINIT(void){
     QString stringa;
     workflow = _WORKFLOW_BOOTINIT;


     if(!isCanConnected()){// Wait until the connection with the CAN Process is established
         if(subWorkflow !=_WI_WAIT_CAN_CONNECTION_0) subWorkflow = _WI_WAIT_CAN_CONNECTION_0;

     }else if(isBootloaderCommunicationPending()){// Waiting for the answer
        QTimer::singleShot(1,this, SLOT(workflowBOOTINIT()));
        return;
     }


    switch(subWorkflow){
        case _WI_BOOTINIT_START:
            qDebug() << "BOARD INITIALIZATION SEQUENCE STARTED";
            subWorkflow++;
            QTimer::singleShot(0,this, SLOT(workflowBOOTINIT()));
            return;

        case _WI_WAIT_CAN_CONNECTION_0:

            qDebug() << "WAITING FOR THE CONNECTION WITH CAN CLIENT";
            subWorkflow++;
            QTimer::singleShot(0,this, SLOT(workflowBOOTINIT()));
            return;

        case _WI_WAIT_CAN_CONNECTION_1:
            if(isCanConnected()) subWorkflow =_WI_GET_INFO_REQ_0;
            qDebug() << "GET BOOTLOADER INFO";
            QTimer::singleShot(0,this, SLOT(workflowBOOTINIT()));
            return;

        case _WI_GET_INFO_REQ_0: // Get info from the Target Bootloader
            if(!bootloaderGetInfo()){
                QTimer::singleShot(100,this, SLOT(workflowBOOTINIT()));
                return;
            }
            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowBOOTINIT()));
            return;

        case _WI_GET_INFO_REQ_1:
            if(!isBootloaderCommunicationOk()){
                subWorkflow--;
                QTimer::singleShot(100,this, SLOT(workflowBOOTINIT()));
                return;
            }

            stringa = "";
            if(getBootloaderError()){
                stringa += QString("BOOTLOADER GET INFO ERROR: %1").arg( getBootloaderError());
            }else{
                if(!isBootloaderPresent()){
                    stringa += QString("BOOTLOADER NOT PRESENT. Application revision: %1.%2.%3").arg(boardAppMaj).arg(boardAppMin).arg(boardAppSub);
                }else{
                    if(isBootloaderRunning()){
                        stringa += QString("BOOTLOADER PRESENT AND RUNNING.");
                    }
                    else stringa += QString("BOOTLOADER PRESENT BUT NOT RUNNING.");
                    stringa += QString("APPREV:%1.%2.%3").arg(boardAppMaj).arg(boardAppMin).arg(boardAppSub);
                    stringa += QString("APPREV:%1.%2.%3").arg(bootloaderMaj).arg(bootloaderMin).arg(bootloaderSub);
                }
            }
            qDebug() << stringa;
            subWorkflow = _WI_BOOTINIT_COMPLETED;
            QTimer::singleShot(0,this, SLOT(workflowBOOTINIT()));
            return;

        case _WI_BOOTINIT_COMPLETED:
            subWorkflow =  0;
            board_initialized = true;
            if(INTERFACE) INTERFACE->EVENT_InitCompleted(); // Send the Event to the Master
            qDebug() << "WORKFLOW INITIALIZATION COMPLETED";
            return;
    }

    qDebug() << "WORKFLOW WRONG FASE DETECTED";

    return;
}



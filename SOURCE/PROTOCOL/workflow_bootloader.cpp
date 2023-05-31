#include "application.h"
#include "can_device_protocol.h"

typedef enum{
    _WF_START_0 = 0,
    _WF_START_1,
    _WF_LOOP_0,
    _WF_BOOTEXIT,
}_WorflowBootloaderSteps;



void deviceProtocol::workflowBOOTLOADER(void){
    workflow = _WORKFLOW_BOOTLOADER;

    // Waiting for the answer
    if(isBootloaderCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowBOOTLOADER()));
        return;
    }

    switch(subWorkflow){

        case _WF_START_0: // Activate the bootloader
            if(!bootloaderStart()){
                QTimer::singleShot(100,this, SLOT(workflowBOOTLOADER()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowBOOTLOADER()));
            return;

        case _WF_START_1:
            if(!isBootloaderCommunicationOk()){
                qDebug() << "BOOTLOADER FRAME TIMEOUT ";
                subWorkflow--;
                QTimer::singleShot(100,this, SLOT(workflowBOOTLOADER()));
                return;
            }

            if(isBootloaderCommandError()){
                qDebug() << "BOOTLOADER COMMAND REJECTED ";
                subWorkflow = 0;
                QTimer::singleShot(10,this, SLOT(workflowIDLE()));
                return;
            }

            qDebug() <<  "BOOTLOADER RESETTING THE APPLICATION ";
            subWorkflow = _WF_LOOP_0;
            QTimer::singleShot(100,this, SLOT(workflowBOOTLOADER()));
            return;

       case _WF_LOOP_0:
            QTimer::singleShot(1000,this, SLOT(workflowBOOTLOADER()));
            return;
    }


}

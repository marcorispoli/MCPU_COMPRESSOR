#include "application.h"
#include "can_device_protocol.h"

typedef enum{
    _WI_GET_APP_REV_0 ,
    _WI_GET_APP_REV_1,
    _WI_GET_APP_PARAM_0 ,
    _WI_GET_APP_PARAM_1,
    _WI_GET_APP_PARAM_2,
    _WI_VERIFY_PARAM_STORE_0,
    _WI_WRITE_PARAM_0,
    _WI_WRITE_PARAM_1,
    _WI_WRITE_PARAM_2,
    _WI_STORE_PARAM_0,
    _WI_STORE_PARAM_1,
    _WI_WRITE_DATA_0,
    _WI_WRITE_DATA_1,
    _WI_WRITE_DATA_2,
    _WI_GET_STATUS_0,
    _WI_GET_STATUS_1,
    _WI_GET_STATUS_2,
    _WI_APPINIT_COMPLETED,
}_WorflowInitSteps;


void deviceProtocol::workflowAPPINIT(void){
    static uint8_t idx;
    bool ris;    
    workflow = _WORKFLOW_APPINIT;


    // Waiting for the answer
    if(isDeviceCommunicationPending()){
        QTimer::singleShot(1,this, SLOT(workflowAPPINIT()));
        return;
    }

    switch(subWorkflow){        
        case _WI_GET_APP_REV_0: // Get Application Revision from the protocol registere
            if(!deviceAccessRegister(canDeviceProtocolFrame::READ_REVISION)){
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            subWorkflow++;
            QTimer::singleShot(10,this, SLOT(workflowAPPINIT()));
            return;

        case _WI_GET_APP_REV_1:
            if(!isDeviceCommunicationOk()){
                qDebug() << "REVISION FRAME TIMEOUT: " << getDeviceFrameErrorStr();
                subWorkflow--;
                QTimer::singleShot(100,this, SLOT(workflowAPPINIT()));
                return;
            }

            qDebug() << "DEVICE REVISION: " << (uchar) deviceRevisionRegister.d[0] << "." <<  deviceRevisionRegister.d[1] << "." << deviceRevisionRegister.d[2];

            subWorkflow = _WI_APPINIT_COMPLETED;
            QTimer::singleShot(0,this, SLOT(workflowAPPINIT()));
            break;

        case _WI_APPINIT_COMPLETED:
            subWorkflow =  0;
            qDebug() << "WORKFLOW INITIALIZATION COMPLETED";
            QTimer::singleShot(100,this, SLOT(workflowIDLE()));
            return;

    }
}

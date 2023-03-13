#ifndef DEVICE_PROTOCOL_H
#define DEVICE_PROTOCOL_H

#include "QObject"
#include "can_device_protocol.h"

/*!
 * \defgroup  deviceModule Device Protocol implementation
 *
 *
 */


class deviceProtocol: public canDeviceProtocol
{
    Q_OBJECT

public:
    explicit deviceProtocol();
    ~deviceProtocol(){};


    typedef enum{
        _WORKFLOW_INITIALIZATION = 0,
        _WORKFLOW_CONFIGURATION,
        _WORKFLOW_IDLE,
    }PROTOCOL_WORKFLOW_e;

    typedef enum{
        STATUS_SYSTEM = 0,
        STATUS_BATTERY,
        STATUS_LEN
    }PROTOCOL_STATUS_ENUM_e;

    typedef enum{
        DATA_OUTPUTS = 0,
        DATA_LEN
    }PROTOCOL_DATA_ENUM_e;

    typedef enum{
        POWER_ON_OFF_DELAY = 0,
        HARDWARE_POWER_OFF_TIME,
        KEEP_ALIVE_POWER_OFF,
        SOFT_POWER_OFF_DELAY,
        LOW_BATT_LEVELS,
        BODY_ROTATION_LOCK_TIME,
        PEDALBOARD_LOCK_TIME,
        MANUAL_ROT_LOCK_TIME,
        XRAY_BUTTON_LOCK_TIME,
        PARAMETER_LEN
    }PROTOCOL_PARAMS_ENUM_e;

    typedef enum{
        EXECUTE_ABORT = 0,
        EXECUTE_POWER_ON_OFF,
    }PROTOCOL_COOMMANDS_ENUM_e;


    inline void requestSoftPowerOff(void){execCmd = EXECUTE_POWER_ON_OFF;};
    inline void requestAbort(void){abortCmd = true;};

    inline canDeviceProtocolFrame::CAN_REGISTER_t getParam(uint8_t data){return paramRegisters[data];};
    inline canDeviceProtocolFrame::CAN_REGISTER_t getData(uint8_t data){return dataRegisters[data];};
    inline canDeviceProtocolFrame::CAN_REGISTER_t getStatus(uint8_t data){return statusRegisters[data];};
    void setData(uint8_t idx, uint8_t data, uint8_t mask, bool stat){
        uchar b = dataRegisters[idx].d[data] &=~ mask;
        if(stat) dataRegisters[idx].d[data] = b | mask;
        else dataRegisters[idx].d[data] = b;
    };


signals:


public slots:


private slots:

    void workflowINITIALIZATION(void);
    void workflowIDLE(void);

public:
    uchar execCmd;
    uchar execParam[4];
    bool  abortCmd;

protected:



private:
    PROTOCOL_WORKFLOW_e workflow;
    uchar subWorkflow;
    uchar sequence;
    bool  rxOk;



};
#endif // DEVICE_PROTOCOL_H

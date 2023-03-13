#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include <QObject>
#include "configfile.h"

class boardConfig : public configFile
{
    public:


    #define REVISION     1  // This is the revision code
    #define CONFIG_FILENAME     "C:\\OEM\\Gantry\\Config\\sw301.cnf" // This is the configuration file name and path

    // This section defines labels helping the param identification along the application
    #define PARAM_0   "POWER_ON_OFF_DELAY"
    #define PARAM_1   "HARDWARE_POWER_OFF_TIME"
    #define PARAM_2   "KEEP_ALIVE_POWER_OFF"
    #define PARAM_3   "SOFT_POWER_OFF_DELAY"
    #define PARAM_4   "LOW_BATT_LEVELS"
    #define PARAM_5   "BODY_ROTATION_LOCK_TIME"
    #define PARAM_6   "PEDALBOARD_LOCK_TIME"
    #define PARAM_7   "MANUAL_ROT_LOCK_TIME"
    #define PARAM_8   "XRAY_BUTTON_LOCK_TIME"


    // your class constructor
    boardConfig():configFile( (const configFile::fileDescriptorT)
        {
            CONFIG_FILENAME, REVISION,
            {{
                { PARAM_0,     {{ "40" }},  "Delay from Power On Off events (0.1s) "},
                { PARAM_1,     {{ "30" }},  "Hardware Power Off button activation time (0.1s)"},
                { PARAM_2,     {{ "60" }},  "Power Down keepalive time (s)"},
                { PARAM_3,     {{ "100" }},  "Soft Power Down waiting time (0.1s)"},
                { PARAM_4,     {{ "100","100" }},  "Low Voltage Battery level (0.1V)"},
                { PARAM_5,     {{ "100","100" }},  "Body lock/unlock time (0.1s)"},
                { PARAM_6,     {{ "100","100" }},  "Pedal lock/unlock time (0.1s)"},
                { PARAM_7,     {{ "100","100" }},  "Man Rot lock/unlock time (0.1s)"},
                { PARAM_8,     {{ "100","100" }},  "XRAY  lock/unlock time (0.1s)"},

            }}
        })
    {
        // Your constructor code ...
        this->loadFile();
    };


}; // End class definition

#endif // BOARDCONFIG_H

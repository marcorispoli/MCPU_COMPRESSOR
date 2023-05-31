#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include <QObject>
#include "configfile.h"

class boardConfig : public configFile
{
    public:


    #define REVISION     1  // This is the revision code
    #define CONFIG_FILENAME     "C:\\OEM\\Gantry\\Config\\mcpu_compressor.cnf" // This is the configuration file name and path

    // This section defines labels helping the param identification along the application
    #define PARAM_0   "PARAM_0"


    // your class constructor
    boardConfig():configFile( (const configFile::fileDescriptorT)
        {
            CONFIG_FILENAME, REVISION,
            {{
                { PARAM_0,     {{ "40" }},  "Delay from Power On Off events (0.1s) "},

            }}
        })
    {
        // Your constructor code ...
        this->loadFile();
    };


}; // End class definition

#endif // BOARDCONFIG_H

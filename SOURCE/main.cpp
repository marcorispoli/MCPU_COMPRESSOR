#define MAIN_CPP

#include "applog.h"
#include "application.h"


/**
 * @brief Main
 * This is the Application Main function.
 *
 *
 * @param argc
 * @param argv
 *  - -file: the debug messages are redirect to the gantrygen.log file;
 *  - -win: the application run with the debug Window;
 *  - -console: the debug messages are forwarded to the console
 *  - No Options: no debug messages are handled
 * @return
 *
 * \ingroup   applicationModule
 */
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    appLog(argc, argv, "C:\\OEM\\Gantry\\Log\\mcpu_compressor.log", debugWindow::debugMessageHandler);

    // Open the system configuration file
    SYSCONFIG = new sysConfig(configFile::_CFG_READONLY);
    if(!SYSCONFIG->isFormatCorrect()) {
        qDebug() << " WRONG CONFIGURATION FILE FORMAT!";
        exit(1);
    }

    // Open the application config file
    CONFIG = new boardConfig();

    // Initialize the WINDOW to nullptr so that in case of Operating mode
    // the application skips the WINDOW callbacks
    WINDOW = nullptr;

    // Create the Window Log if necessary
    if(appLog::isWindow){
        WINDOW = new debugWindow();
        WINDOW->show();
    }

    // Open the server for the external commands
    INTERFACE = new Interface();

    // Open the communication protocol
    PROTOCOL = new deviceProtocol();

    // Start communication with the Master
    INTERFACE->Start();
    return a.exec();
}


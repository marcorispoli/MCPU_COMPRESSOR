#ifndef APPLICATION_H
#define APPLICATION_H

/*!
 * \defgroup  applicationModule Application Module.
 */

/*!
 * \defgroup  libraryModules Library Modules Used in the Application.
 */


/*!
 * \mainpage
 *
 * # GENERAL OVERVIEW
 *
 * The Application can run without debug messages or alternatively
 * can be launched with -file, -win or -console option:
 * - -win: allows to run the application with a graphical window to
 * provide manual interaction with the Power Service device;
 * - -file: the Application redirects the debug messages to a file
 * in C:/OEM/Logs/GANTRY/PowerService.log
 * - -console: redirects the debug messages to the standard console
 *
 * # DEPENDENCIES AND CONFIGURATION FILES
 *
 *
 * # APPLICATION MODULES
 *
 * The Application implements the following modules:
 * - @ref applicationModule : defines constant along the application
 * - @ref libraryModules : this is the set of the libraries used in the current application;
 * - @ref interfaceModule : this is the communication socket to receive command from Gantry;
 * - @ref protocolModule : this is the module implementing the Can Device protocol;
 * - @ref windowModule : this is an optional Windows interface used for Service/Debug;
 *
 * # SOFTWARE LICENCING
 *
 * The Application has been developed with the Qt Libraries
 * with the LGPL 3.0 licences.
 *
 * The Application uses the following Libraries:
 * - Network (LGPL-3.0)
 * - Core (LGPL-3.0);
 *
 * The Application uses only those libraries without change them and they are
 * dinamically linked into the application.
 */


/**
* @brief Application constants definition
*
*  This Namespace defines all the MAIN constants that are used along the \n
*  Application in order to interface the Generator and the Gantry.
*
* \ingroup applicationModule
*/
namespace Application
{
   static const char*           IP_CAN_ADDRESS = "127.0.0.1"; //!< Can Client Server IP address
   static const unsigned short  CAN_PORT = 10001; //!< Can Client Server Port
   static const char*           IP_INTERFACE_ADDRESS = "127.0.0.1"; //!< Motor Interface IP address
   static const unsigned short  INTERFACE_PORT = 10004; //!< Power Service Interface Port
   static const unsigned char   DEVICE_ID = 0x11; //!< Power Service Can Device ID
}


#include <QApplication>
#include <QObject>
#include <QTimer>
#include "time.h"
#include "canclient.h"
#include "window.h"
#include "interface.h"
#include "can_device_protocol.h"
#include "device_protocol.h"
#include "boardconfig.h"

#define WINDOW          window
#define INTERFACE       pInterface
#define DEBUG           window
#define PROTOCOL        pProtocol
#define CONFIG          pConfig

// Global definitions
#ifdef MAIN_CPP
     debugWindow*                WINDOW;
     Interface*                  INTERFACE;
     deviceProtocol*             PROTOCOL;
     boardConfig*                CONFIG;

#else
    extern debugWindow*                WINDOW;
    extern Interface*                  INTERFACE;
    extern deviceProtocol*             PROTOCOL;
    extern boardConfig*                CONFIG;
#endif

#ifdef TIME_MEASURE
    #define T1START  this->t1 = clock()
    #define T1MEASURE(x) { qDebug() << x << ((double)(clock() - this->t1)/CLOCKS_PER_SEC);}
#else
    #define T1START
    #define T1MEASURE(x)
#endif

#endif // APPLICATION_H

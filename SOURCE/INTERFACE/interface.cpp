#include "application.h"
#include <QStringConverter>

/**
 * @brief Interface::Interface
 *
 * @param
 * - ipaddress: IP where server will be bounded;
 * - port: bounding port
 *
 */
Interface::Interface(void):applicationInterface(SYSCONFIG->getParam<QString>(SYS_COMPRESSOR_PROCESS_PARAM,SYS_PROCESS_IP),SYSCONFIG->getParam<int>(SYS_COMPRESSOR_PROCESS_PARAM,SYS_PROCESS_PORT))
{

}

uint Interface::handleReceivedCommand(QList<QString>* frame, QList<QString>* answer){

    if(frame->at(2) == "GetRevision")  return GetStatus(answer);
    return 1;
}

uint Interface::GetStatus( QList<QString>* answer){
    answer->clear();
    answer->append(QString("%1").arg(Application::APP_MAJ_REV));
    answer->append(QString("%1").arg(Application::APP_MIN_REV));
    answer->append(QString("%1").arg(Application::APP_SUB_REV));
    return 0;
}

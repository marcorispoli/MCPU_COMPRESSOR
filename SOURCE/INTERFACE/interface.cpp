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
    if(frame->at(2) == "GetRevision")  return GetRevision(answer);
    else if(frame->at(2) == "BoardInitialize")  return BoardInitialize(answer);
    return 1;
}

uint Interface::GetRevision( QList<QString>* answer){
    answer->clear();
    answer->append(QString("%1").arg(Application::APP_MAJ_REV));
    answer->append(QString("%1").arg(Application::APP_MIN_REV));
    answer->append(QString("%1").arg(Application::APP_SUB_REV));
    return 0;
}

uint Interface::BoardInitialize( QList<QString>* answer){
    if(PROTOCOL->isBoardInitialized()) EVENT_InitCompleted();
    else PROTOCOL->boardInitialize();
    return 0;
}



void Interface::EVENT_InitCompleted(void){
    QList<QString> params;

    params.append(QString("%1").arg(PROTOCOL->getBootloaderError()));

    if(PROTOCOL->isBootloaderPresent()) params.append(QString("1"));
    else params.append(QString("0"));

    if(PROTOCOL->isBootloaderRunning()) params.append(QString("1"));
    else params.append(QString("0"));

    params.append(QString("%1").arg(PROTOCOL->getBoardAppMaj()));
    params.append(QString("%1").arg(PROTOCOL->getBoardAppMin()));
    params.append(QString("%1").arg(PROTOCOL->getBoardAppSub()));

    params.append(QString("%1").arg(PROTOCOL->getBootloaderMaj()));
    params.append(QString("%1").arg(PROTOCOL->getBootloaderMin()));
    params.append(QString("%1").arg(PROTOCOL->getBootloaderSub()));

    sendEvent(EVENT_INIT_COMPLETED, &params);
}

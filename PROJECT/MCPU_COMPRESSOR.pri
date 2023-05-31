
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#Include supporto per Qt Network (moduli TCP/IP)
QT += network

FORMS += \
    $${TARGET_SOURCE}/WINDOW/window.ui \

RESOURCES += \
    $${TARGET_RESOURCE}/assets.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

SOURCES += \
    $${TARGET_SOURCE}/main.cpp \
    $${SHARED}/APPLICATION_INTERFACE/applicationInterface.cpp \
    $${SHARED}/CAN_CLIENT/canclient.cpp \
    $${SHARED}/APPLOG/applog.cpp \
    $${SHARED}/CONFIGFILE/configfile.cpp \
    $${SHARED}/CAN_DEVICE_PROTOCOL/can_device_protocol.cpp \
    $${SHARED}/CAN_DEVICE_PROTOCOL/can_bootloader_protocol.cpp \
    $${TARGET_SOURCE}/INTERFACE/interface.cpp \
    $${TARGET_SOURCE}/PROTOCOL/device_protocol.cpp \
    $${TARGET_SOURCE}/PROTOCOL/workflow_bootloader.cpp \
    $${TARGET_SOURCE}/PROTOCOL/workflow_init.cpp \
    $${TARGET_SOURCE}/PROTOCOL/workflow_idle.cpp \
    $${TARGET_SOURCE}/WINDOW/window.cpp \



HEADERS += \
    $${TARGET_SOURCE}/application.h \
    $${SHARED}/APPLICATION_INTERFACE/applicationInterface.h \
    $${SHARED}/CAN_CLIENT/canclient.h \
    $${SHARED}/APPLOG/applog.h \
    $${SHARED}/CONFIGFILE/configfile.h \
    $${SHARED}/CONFIGFILE/sysconfig.h \
    $${SHARED}/CAN_DEVICE_PROTOCOL/can_device_protocol.h \
    $${SHARED}/CAN_DEVICE_PROTOCOL/can_bootloader_protocol.h \
    $${TARGET_SOURCE}/INTERFACE/interface.h \
    $${TARGET_SOURCE}/PROTOCOL/device_protocol.h \
    $${TARGET_SOURCE}/WINDOW/window.h \
    $${TARGET_SOURCE}/CONFIGURATION/boardconfig.h \


# Aggiunge tutti i path di progetto
INCLUDEPATH += \
    $${SHARED}/APPLICATION_INTERFACE \
    $${SHARED}/CAN_CLIENT \
    $${SHARED}/APPLOG \
    $${SHARED}/CONFIGFILE \
    $${SHARED}/CAN_DEVICE_PROTOCOL \
    $${TARGET_SOURCE} \
    $${TARGET_SOURCE}/INTERFACE \
    $${TARGET_SOURCE}/PROTOCOL \
    $${TARGET_SOURCE}/WINDOW  \
    $${TARGET_SOURCE}/CONFIGURATION  \

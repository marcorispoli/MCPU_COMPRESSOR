/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugWindow
{
public:
    QFrame *mainFrame;
    QFrame *connectionFrame_4;
    QPlainTextEdit *canText;
    QPushButton *logClearButton;
    QCheckBox *logEnableCheck;
    QPlainTextEdit *debugText;
    QPushButton *debugClearButton;
    QLabel *label_16;
    QCheckBox *debugEnable;
    QLabel *label_17;
    QFrame *frame;
    QLabel *label_18;
    QLineEdit *param0_0;
    QLabel *label_19;
    QLineEdit *param1_0;
    QLabel *label_20;
    QLineEdit *param2_0;
    QLabel *label_21;
    QLineEdit *param3_0;
    QLabel *label_22;
    QLineEdit *param4_0;
    QLineEdit *param4_1;
    QLabel *label_24;
    QLineEdit *param5_0;
    QLineEdit *param5_1;
    QLineEdit *param6_1;
    QLineEdit *param6_0;
    QLabel *label_26;
    QLineEdit *param7_1;
    QLineEdit *param7_0;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *param8_0;
    QLineEdit *param8_1;
    QPushButton *configureButton;
    QFrame *frame_3;
    QCheckBox *data0_0;
    QCheckBox *data0_1;
    QCheckBox *data0_2;
    QCheckBox *data0_3;
    QCheckBox *data0_4;
    QCheckBox *data0_5;
    QCheckBox *data1_0;
    QCheckBox *data1_1;
    QCheckBox *data1_2;
    QCheckBox *data1_3;
    QCheckBox *data1_4;
    QCheckBox *data1_5;
    QFrame *frame_4;
    QRadioButton *status0_0;
    QRadioButton *status0_1;
    QRadioButton *status0_2;
    QRadioButton *status0_3;
    QRadioButton *status0_4;
    QRadioButton *status0_5;
    QRadioButton *status0_6;
    QRadioButton *status0_7;
    QRadioButton *status1_7;
    QRadioButton *status1_3;
    QRadioButton *status1_0;
    QRadioButton *status1_4;
    QRadioButton *status1_6;
    QRadioButton *status1_1;
    QRadioButton *status1_2;
    QRadioButton *status1_5;
    QRadioButton *status2_5;
    QRadioButton *status2_3;
    QRadioButton *status2_1;
    QRadioButton *status2_0;
    QRadioButton *status2_2;
    QRadioButton *status2_4;
    QRadioButton *status3_3;
    QRadioButton *status3_2;
    QRadioButton *status3_1;
    QRadioButton *status3_0;
    QRadioButton *status2_6;
    QPushButton *softPoffButton;
    QPushButton *abortButton;
    QFrame *frame_2;
    QLineEdit *batt1V;
    QLineEdit *batt2V;
    QLabel *label_23;
    QLabel *label_25;

    void setupUi(QWidget *debugWindow)
    {
        if (debugWindow->objectName().isEmpty())
            debugWindow->setObjectName(QString::fromUtf8("debugWindow"));
        debugWindow->resize(800, 600);
        debugWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 170, 255);"));
        mainFrame = new QFrame(debugWindow);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        mainFrame->setGeometry(QRect(0, 0, 800, 600));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        mainFrame->setFont(font);
        mainFrame->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid; \n"
"border-color: darkblue;\n"
"border-color: rgb(0, 0, 127);"));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);
        connectionFrame_4 = new QFrame(mainFrame);
        connectionFrame_4->setObjectName(QString::fromUtf8("connectionFrame_4"));
        connectionFrame_4->setGeometry(QRect(10, 30, 361, 561));
        connectionFrame_4->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid; \n"
"border-color: darkblue;\n"
"border-color: rgb(0, 0, 127);\n"
""));
        connectionFrame_4->setFrameShape(QFrame::StyledPanel);
        connectionFrame_4->setFrameShadow(QFrame::Raised);
        canText = new QPlainTextEdit(connectionFrame_4);
        canText->setObjectName(QString::fromUtf8("canText"));
        canText->setGeometry(QRect(10, 50, 341, 211));
        QFont font1;
        font1.setPointSize(6);
        canText->setFont(font1);
        canText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        logClearButton = new QPushButton(connectionFrame_4);
        logClearButton->setObjectName(QString::fromUtf8("logClearButton"));
        logClearButton->setGeometry(QRect(10, 10, 121, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        logClearButton->setFont(font2);
        logClearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        logEnableCheck = new QCheckBox(connectionFrame_4);
        logEnableCheck->setObjectName(QString::fromUtf8("logEnableCheck"));
        logEnableCheck->setGeometry(QRect(170, 11, 71, 31));
        debugText = new QPlainTextEdit(connectionFrame_4);
        debugText->setObjectName(QString::fromUtf8("debugText"));
        debugText->setGeometry(QRect(10, 340, 341, 211));
        debugText->setFont(font1);
        debugText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        debugClearButton = new QPushButton(connectionFrame_4);
        debugClearButton->setObjectName(QString::fromUtf8("debugClearButton"));
        debugClearButton->setGeometry(QRect(10, 300, 121, 31));
        debugClearButton->setFont(font2);
        debugClearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_16 = new QLabel(connectionFrame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(270, 320, 71, 20));
        label_16->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        debugEnable = new QCheckBox(connectionFrame_4);
        debugEnable->setObjectName(QString::fromUtf8("debugEnable"));
        debugEnable->setGeometry(QRect(170, 300, 71, 31));
        debugEnable->setChecked(true);
        label_17 = new QLabel(connectionFrame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(270, 30, 81, 20));
        label_17->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame = new QFrame(mainFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(520, 350, 261, 241));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 10, 101, 20));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        label_18->setFont(font3);
        label_18->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param0_0 = new QLineEdit(frame);
        param0_0->setObjectName(QString::fromUtf8("param0_0"));
        param0_0->setGeometry(QRect(130, 10, 51, 21));
        param0_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 30, 101, 20));
        label_19->setFont(font3);
        label_19->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param1_0 = new QLineEdit(frame);
        param1_0->setObjectName(QString::fromUtf8("param1_0"));
        param1_0->setGeometry(QRect(130, 30, 51, 21));
        param1_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 50, 91, 20));
        label_20->setFont(font3);
        label_20->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param2_0 = new QLineEdit(frame);
        param2_0->setObjectName(QString::fromUtf8("param2_0"));
        param2_0->setGeometry(QRect(130, 50, 51, 21));
        param2_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 70, 101, 20));
        label_21->setFont(font3);
        label_21->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param3_0 = new QLineEdit(frame);
        param3_0->setObjectName(QString::fromUtf8("param3_0"));
        param3_0->setGeometry(QRect(130, 70, 51, 21));
        param3_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 90, 101, 20));
        label_22->setFont(font3);
        label_22->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param4_0 = new QLineEdit(frame);
        param4_0->setObjectName(QString::fromUtf8("param4_0"));
        param4_0->setGeometry(QRect(130, 90, 51, 21));
        param4_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param4_1 = new QLineEdit(frame);
        param4_1->setObjectName(QString::fromUtf8("param4_1"));
        param4_1->setGeometry(QRect(180, 90, 51, 21));
        param4_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 110, 101, 20));
        label_24->setFont(font3);
        label_24->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param5_0 = new QLineEdit(frame);
        param5_0->setObjectName(QString::fromUtf8("param5_0"));
        param5_0->setGeometry(QRect(130, 110, 51, 21));
        param5_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param5_1 = new QLineEdit(frame);
        param5_1->setObjectName(QString::fromUtf8("param5_1"));
        param5_1->setGeometry(QRect(180, 110, 51, 21));
        param5_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param6_1 = new QLineEdit(frame);
        param6_1->setObjectName(QString::fromUtf8("param6_1"));
        param6_1->setGeometry(QRect(180, 130, 51, 21));
        param6_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param6_0 = new QLineEdit(frame);
        param6_0->setObjectName(QString::fromUtf8("param6_0"));
        param6_0->setGeometry(QRect(130, 130, 51, 21));
        param6_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 130, 101, 20));
        label_26->setFont(font3);
        label_26->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param7_1 = new QLineEdit(frame);
        param7_1->setObjectName(QString::fromUtf8("param7_1"));
        param7_1->setGeometry(QRect(180, 150, 51, 21));
        param7_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param7_0 = new QLineEdit(frame);
        param7_0->setObjectName(QString::fromUtf8("param7_0"));
        param7_0->setGeometry(QRect(130, 150, 51, 21));
        param7_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(frame);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 150, 81, 20));
        label_29->setFont(font3);
        label_29->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_30 = new QLabel(frame);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 170, 91, 20));
        label_30->setFont(font3);
        label_30->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        param8_0 = new QLineEdit(frame);
        param8_0->setObjectName(QString::fromUtf8("param8_0"));
        param8_0->setGeometry(QRect(130, 170, 51, 21));
        param8_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        param8_1 = new QLineEdit(frame);
        param8_1->setObjectName(QString::fromUtf8("param8_1"));
        param8_1->setGeometry(QRect(180, 170, 51, 21));
        param8_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        configureButton = new QPushButton(frame);
        configureButton->setObjectName(QString::fromUtf8("configureButton"));
        configureButton->setGeometry(QRect(10, 200, 221, 31));
        configureButton->setFont(font2);
        configureButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        frame_3 = new QFrame(mainFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(510, 30, 141, 261));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        data0_0 = new QCheckBox(frame_3);
        data0_0->setObjectName(QString::fromUtf8("data0_0"));
        data0_0->setGeometry(QRect(10, 10, 121, 22));
        data0_1 = new QCheckBox(frame_3);
        data0_1->setObjectName(QString::fromUtf8("data0_1"));
        data0_1->setGeometry(QRect(10, 30, 121, 22));
        data0_2 = new QCheckBox(frame_3);
        data0_2->setObjectName(QString::fromUtf8("data0_2"));
        data0_2->setGeometry(QRect(10, 50, 121, 22));
        data0_3 = new QCheckBox(frame_3);
        data0_3->setObjectName(QString::fromUtf8("data0_3"));
        data0_3->setGeometry(QRect(10, 70, 121, 22));
        data0_4 = new QCheckBox(frame_3);
        data0_4->setObjectName(QString::fromUtf8("data0_4"));
        data0_4->setGeometry(QRect(10, 90, 121, 22));
        data0_5 = new QCheckBox(frame_3);
        data0_5->setObjectName(QString::fromUtf8("data0_5"));
        data0_5->setGeometry(QRect(10, 110, 121, 22));
        data1_0 = new QCheckBox(frame_3);
        data1_0->setObjectName(QString::fromUtf8("data1_0"));
        data1_0->setGeometry(QRect(10, 130, 121, 22));
        data1_1 = new QCheckBox(frame_3);
        data1_1->setObjectName(QString::fromUtf8("data1_1"));
        data1_1->setGeometry(QRect(10, 150, 121, 22));
        data1_2 = new QCheckBox(frame_3);
        data1_2->setObjectName(QString::fromUtf8("data1_2"));
        data1_2->setGeometry(QRect(10, 170, 121, 22));
        data1_3 = new QCheckBox(frame_3);
        data1_3->setObjectName(QString::fromUtf8("data1_3"));
        data1_3->setGeometry(QRect(10, 190, 121, 22));
        data1_4 = new QCheckBox(frame_3);
        data1_4->setObjectName(QString::fromUtf8("data1_4"));
        data1_4->setGeometry(QRect(10, 210, 121, 22));
        data1_5 = new QCheckBox(frame_3);
        data1_5->setObjectName(QString::fromUtf8("data1_5"));
        data1_5->setGeometry(QRect(10, 230, 121, 22));
        frame_4 = new QFrame(mainFrame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(370, 30, 141, 561));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        status0_0 = new QRadioButton(frame_4);
        status0_0->setObjectName(QString::fromUtf8("status0_0"));
        status0_0->setGeometry(QRect(10, 10, 121, 22));
        status0_0->setAutoExclusive(false);
        status0_1 = new QRadioButton(frame_4);
        status0_1->setObjectName(QString::fromUtf8("status0_1"));
        status0_1->setGeometry(QRect(10, 30, 121, 22));
        status0_1->setAutoExclusive(false);
        status0_2 = new QRadioButton(frame_4);
        status0_2->setObjectName(QString::fromUtf8("status0_2"));
        status0_2->setGeometry(QRect(10, 50, 121, 22));
        status0_2->setAutoExclusive(false);
        status0_3 = new QRadioButton(frame_4);
        status0_3->setObjectName(QString::fromUtf8("status0_3"));
        status0_3->setGeometry(QRect(10, 70, 121, 22));
        status0_3->setAutoExclusive(false);
        status0_4 = new QRadioButton(frame_4);
        status0_4->setObjectName(QString::fromUtf8("status0_4"));
        status0_4->setGeometry(QRect(10, 90, 121, 22));
        status0_4->setAutoExclusive(false);
        status0_5 = new QRadioButton(frame_4);
        status0_5->setObjectName(QString::fromUtf8("status0_5"));
        status0_5->setGeometry(QRect(10, 110, 121, 22));
        status0_5->setAutoExclusive(false);
        status0_6 = new QRadioButton(frame_4);
        status0_6->setObjectName(QString::fromUtf8("status0_6"));
        status0_6->setGeometry(QRect(10, 130, 121, 22));
        status0_6->setAutoExclusive(false);
        status0_7 = new QRadioButton(frame_4);
        status0_7->setObjectName(QString::fromUtf8("status0_7"));
        status0_7->setGeometry(QRect(10, 150, 121, 22));
        status0_7->setAutoExclusive(false);
        status1_7 = new QRadioButton(frame_4);
        status1_7->setObjectName(QString::fromUtf8("status1_7"));
        status1_7->setGeometry(QRect(10, 310, 121, 22));
        status1_7->setAutoExclusive(false);
        status1_3 = new QRadioButton(frame_4);
        status1_3->setObjectName(QString::fromUtf8("status1_3"));
        status1_3->setGeometry(QRect(10, 230, 121, 22));
        status1_3->setAutoExclusive(false);
        status1_0 = new QRadioButton(frame_4);
        status1_0->setObjectName(QString::fromUtf8("status1_0"));
        status1_0->setGeometry(QRect(10, 170, 121, 22));
        status1_0->setAutoExclusive(false);
        status1_4 = new QRadioButton(frame_4);
        status1_4->setObjectName(QString::fromUtf8("status1_4"));
        status1_4->setGeometry(QRect(10, 250, 121, 22));
        status1_4->setAutoExclusive(false);
        status1_6 = new QRadioButton(frame_4);
        status1_6->setObjectName(QString::fromUtf8("status1_6"));
        status1_6->setGeometry(QRect(10, 290, 121, 22));
        status1_6->setAutoExclusive(false);
        status1_1 = new QRadioButton(frame_4);
        status1_1->setObjectName(QString::fromUtf8("status1_1"));
        status1_1->setGeometry(QRect(10, 190, 121, 22));
        status1_1->setAutoExclusive(false);
        status1_2 = new QRadioButton(frame_4);
        status1_2->setObjectName(QString::fromUtf8("status1_2"));
        status1_2->setGeometry(QRect(10, 210, 121, 22));
        status1_2->setAutoExclusive(false);
        status1_5 = new QRadioButton(frame_4);
        status1_5->setObjectName(QString::fromUtf8("status1_5"));
        status1_5->setGeometry(QRect(10, 270, 121, 22));
        status1_5->setAutoExclusive(false);
        status2_5 = new QRadioButton(frame_4);
        status2_5->setObjectName(QString::fromUtf8("status2_5"));
        status2_5->setGeometry(QRect(10, 430, 121, 22));
        status2_5->setAutoExclusive(false);
        status2_3 = new QRadioButton(frame_4);
        status2_3->setObjectName(QString::fromUtf8("status2_3"));
        status2_3->setGeometry(QRect(10, 390, 121, 22));
        status2_3->setAutoExclusive(false);
        status2_1 = new QRadioButton(frame_4);
        status2_1->setObjectName(QString::fromUtf8("status2_1"));
        status2_1->setGeometry(QRect(10, 350, 121, 22));
        status2_1->setAutoExclusive(false);
        status2_0 = new QRadioButton(frame_4);
        status2_0->setObjectName(QString::fromUtf8("status2_0"));
        status2_0->setGeometry(QRect(10, 330, 121, 22));
        status2_0->setAutoExclusive(false);
        status2_2 = new QRadioButton(frame_4);
        status2_2->setObjectName(QString::fromUtf8("status2_2"));
        status2_2->setGeometry(QRect(10, 370, 121, 22));
        status2_2->setAutoExclusive(false);
        status2_4 = new QRadioButton(frame_4);
        status2_4->setObjectName(QString::fromUtf8("status2_4"));
        status2_4->setGeometry(QRect(10, 410, 121, 22));
        status2_4->setAutoExclusive(false);
        status3_3 = new QRadioButton(frame_4);
        status3_3->setObjectName(QString::fromUtf8("status3_3"));
        status3_3->setGeometry(QRect(10, 530, 121, 22));
        status3_3->setAutoExclusive(false);
        status3_2 = new QRadioButton(frame_4);
        status3_2->setObjectName(QString::fromUtf8("status3_2"));
        status3_2->setGeometry(QRect(10, 510, 121, 22));
        status3_2->setAutoExclusive(false);
        status3_1 = new QRadioButton(frame_4);
        status3_1->setObjectName(QString::fromUtf8("status3_1"));
        status3_1->setGeometry(QRect(10, 490, 121, 22));
        status3_1->setAutoExclusive(false);
        status3_0 = new QRadioButton(frame_4);
        status3_0->setObjectName(QString::fromUtf8("status3_0"));
        status3_0->setGeometry(QRect(10, 470, 121, 22));
        status3_0->setAutoExclusive(false);
        status2_6 = new QRadioButton(frame_4);
        status2_6->setObjectName(QString::fromUtf8("status2_6"));
        status2_6->setGeometry(QRect(10, 450, 121, 22));
        status2_6->setAutoExclusive(false);
        softPoffButton = new QPushButton(mainFrame);
        softPoffButton->setObjectName(QString::fromUtf8("softPoffButton"));
        softPoffButton->setGeometry(QRect(670, 130, 101, 31));
        softPoffButton->setFont(font2);
        softPoffButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        abortButton = new QPushButton(mainFrame);
        abortButton->setObjectName(QString::fromUtf8("abortButton"));
        abortButton->setGeometry(QRect(670, 170, 101, 31));
        abortButton->setFont(font2);
        abortButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        frame_2 = new QFrame(mainFrame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(650, 30, 131, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        batt1V = new QLineEdit(frame_2);
        batt1V->setObjectName(QString::fromUtf8("batt1V"));
        batt1V->setGeometry(QRect(60, 20, 61, 21));
        batt1V->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        batt2V = new QLineEdit(frame_2);
        batt2V->setObjectName(QString::fromUtf8("batt2V"));
        batt2V->setGeometry(QRect(60, 50, 61, 21));
        batt2V->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(frame_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 20, 41, 20));
        label_23->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_25 = new QLabel(frame_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 50, 41, 20));
        label_25->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"border-width: 0px;\n"
""));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(debugWindow);

        QMetaObject::connectSlotsByName(debugWindow);
    } // setupUi

    void retranslateUi(QWidget *debugWindow)
    {
        debugWindow->setWindowTitle(QCoreApplication::translate("debugWindow", "GENERATOR DEBUG WINDOW", nullptr));
        canText->setPlainText(QCoreApplication::translate("debugWindow", "-----\n"
"", nullptr));
        logClearButton->setText(QCoreApplication::translate("debugWindow", "CLEAR", nullptr));
        logEnableCheck->setText(QCoreApplication::translate("debugWindow", "ENABLE", nullptr));
        debugText->setPlainText(QCoreApplication::translate("debugWindow", "-----\n"
"", nullptr));
        debugClearButton->setText(QCoreApplication::translate("debugWindow", "CLEAR", nullptr));
        label_16->setText(QCoreApplication::translate("debugWindow", "DEBUG TEXT", nullptr));
        debugEnable->setText(QCoreApplication::translate("debugWindow", "ENABLE", nullptr));
        label_17->setText(QCoreApplication::translate("debugWindow", "CAN FRAMES", nullptr));
        label_18->setText(QCoreApplication::translate("debugWindow", "DELAY PON-POFF", nullptr));
        param0_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_19->setText(QCoreApplication::translate("debugWindow", "HW POFF BUTTON ", nullptr));
        param1_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_20->setText(QCoreApplication::translate("debugWindow", "PDOWN TIME", nullptr));
        param2_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_21->setText(QCoreApplication::translate("debugWindow", "SOFT POFF DELAY", nullptr));
        param3_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_22->setText(QCoreApplication::translate("debugWindow", "LOW VOLT BATT1", nullptr));
        param4_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param4_1->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_24->setText(QCoreApplication::translate("debugWindow", "BODY LOCK TIME", nullptr));
        param5_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param5_1->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param6_1->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param6_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_26->setText(QCoreApplication::translate("debugWindow", "PEDAL LOCK TIME", nullptr));
        param7_1->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param7_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_29->setText(QCoreApplication::translate("debugWindow", "ROT LOCK TIME", nullptr));
        label_30->setText(QCoreApplication::translate("debugWindow", "XRAY LOCK TIME", nullptr));
        param8_0->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        param8_1->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        configureButton->setText(QCoreApplication::translate("debugWindow", "CONFIGURE", nullptr));
        data0_0->setText(QCoreApplication::translate("debugWindow", "powerlock", nullptr));
        data0_1->setText(QCoreApplication::translate("debugWindow", "motor_ena", nullptr));
        data0_2->setText(QCoreApplication::translate("debugWindow", "motor_safety_ena", nullptr));
        data0_3->setText(QCoreApplication::translate("debugWindow", "compressor_ena", nullptr));
        data0_4->setText(QCoreApplication::translate("debugWindow", "calibration_ena", nullptr));
        data0_5->setText(QCoreApplication::translate("debugWindow", "xray_ena", nullptr));
        data1_0->setText(QCoreApplication::translate("debugWindow", "burnin activation", nullptr));
        data1_1->setText(QCoreApplication::translate("debugWindow", "manual buzzer ", nullptr));
        data1_2->setText(QCoreApplication::translate("debugWindow", "buzzer mode", nullptr));
        data1_3->setText(QCoreApplication::translate("debugWindow", "xray led", nullptr));
        data1_4->setText(QCoreApplication::translate("debugWindow", "xray lamp-1", nullptr));
        data1_5->setText(QCoreApplication::translate("debugWindow", "xray lamp-2", nullptr));
        status0_0->setText(QCoreApplication::translate("debugWindow", "errors", nullptr));
        status0_1->setText(QCoreApplication::translate("debugWindow", "emergency", nullptr));
        status0_2->setText(QCoreApplication::translate("debugWindow", "powerdown", nullptr));
        status0_3->setText(QCoreApplication::translate("debugWindow", "safety switch", nullptr));
        status0_4->setText(QCoreApplication::translate("debugWindow", "soft power off req", nullptr));
        status0_5->setText(QCoreApplication::translate("debugWindow", "batt1-low", nullptr));
        status0_6->setText(QCoreApplication::translate("debugWindow", "batt2-low", nullptr));
        status0_7->setText(QCoreApplication::translate("debugWindow", "battery-ena", nullptr));
        status1_7->setText(QCoreApplication::translate("debugWindow", "BODY CCW req", nullptr));
        status1_3->setText(QCoreApplication::translate("debugWindow", "SLIDE DWN req", nullptr));
        status1_0->setText(QCoreApplication::translate("debugWindow", "ARM UP req", nullptr));
        status1_4->setText(QCoreApplication::translate("debugWindow", "ROT CW req", nullptr));
        status1_6->setText(QCoreApplication::translate("debugWindow", "BODY CW req", nullptr));
        status1_1->setText(QCoreApplication::translate("debugWindow", "ARM DWN req", nullptr));
        status1_2->setText(QCoreApplication::translate("debugWindow", "SLIDE UP req", nullptr));
        status1_5->setText(QCoreApplication::translate("debugWindow", "ROT CCW req", nullptr));
        status2_5->setText(QCoreApplication::translate("debugWindow", "burnin jumper", nullptr));
        status2_3->setText(QCoreApplication::translate("debugWindow", "xray button", nullptr));
        status2_1->setText(QCoreApplication::translate("debugWindow", "mot safety ena", nullptr));
        status2_0->setText(QCoreApplication::translate("debugWindow", "mot dc-ok", nullptr));
        status2_2->setText(QCoreApplication::translate("debugWindow", "compression on", nullptr));
        status2_4->setText(QCoreApplication::translate("debugWindow", "closed door", nullptr));
        status3_3->setText(QCoreApplication::translate("debugWindow", "pedal_cmp_dwn", nullptr));
        status3_2->setText(QCoreApplication::translate("debugWindow", "pedal_cmp_up", nullptr));
        status3_1->setText(QCoreApplication::translate("debugWindow", "pedal_dwn", nullptr));
        status3_0->setText(QCoreApplication::translate("debugWindow", "pedal_up", nullptr));
        status2_6->setText(QCoreApplication::translate("debugWindow", "power lock", nullptr));
        softPoffButton->setText(QCoreApplication::translate("debugWindow", "SOFT POFF", nullptr));
        abortButton->setText(QCoreApplication::translate("debugWindow", "ABORT", nullptr));
        batt1V->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        batt2V->setText(QCoreApplication::translate("debugWindow", "255", nullptr));
        label_23->setText(QCoreApplication::translate("debugWindow", "BATT 1", nullptr));
        label_25->setText(QCoreApplication::translate("debugWindow", "BATT 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debugWindow: public Ui_debugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H

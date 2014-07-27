/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QFrame *line;
    QFrame *SerialFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *SerialLeyout;
    QFrame *cubeFrame;
    QFrame *graphFrame;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLCDNumber *accx;
    QLCDNumber *accy;
    QLCDNumber *accz;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *pwm_1;
    QLCDNumber *pwm_2;
    QLCDNumber *pwm_3;
    QLCDNumber *pwm_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QFrame *line_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSlider *verticalSlider_1;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_8;
    QSlider *verticalSlider_9;
    QSlider *verticalSlider_10;
    QSlider *verticalSlider_11;
    QSlider *verticalSlider_12;
    QSlider *verticalSlider_13;
    QSlider *verticalSlider_14;
    QSlider *verticalSlider_15;
    QSlider *verticalSlider_16;
    QSlider *verticalSlider_17;
    QSlider *verticalSlider_18;
    QSlider *verticalSlider_19;
    QSlider *verticalSlider_20;
    QHBoxLayout *horizontalLayout_6;
    QLCDNumber *lcdNumber_1;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdNumber_6;
    QLCDNumber *lcdNumber_7;
    QLCDNumber *lcdNumber_8;
    QLCDNumber *lcdNumber_9;
    QLCDNumber *lcdNumber_10;
    QLCDNumber *lcdNumber_11;
    QLCDNumber *lcdNumber_12;
    QLCDNumber *lcdNumber_13;
    QLCDNumber *lcdNumber_14;
    QLCDNumber *lcdNumber_15;
    QLCDNumber *lcdNumber_16;
    QLCDNumber *lcdNumber_17;
    QLCDNumber *lcdNumber_18;
    QLCDNumber *lcdNumber_19;
    QLCDNumber *lcdNumber_20;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *savecurve;
    QPushButton *loadcurve;
    QDoubleSpinBox *derivativeweight;
    QSpinBox *story_point_num;
    QPushButton *stop;
    QDoubleSpinBox *proportionalweight;
    QDoubleSpinBox *integrativeweight;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(911, 945);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(385, 9, 16, 568));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        SerialFrame = new QFrame(centralWidget);
        SerialFrame->setObjectName(QStringLiteral("SerialFrame"));
        SerialFrame->setGeometry(QRect(9, 9, 370, 281));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialFrame->sizePolicy().hasHeightForWidth());
        SerialFrame->setSizePolicy(sizePolicy);
        SerialFrame->setMinimumSize(QSize(200, 100));
        SerialFrame->setAutoFillBackground(false);
        SerialFrame->setFrameShape(QFrame::Box);
        SerialFrame->setFrameShadow(QFrame::Raised);
        SerialFrame->setLineWidth(1);
        SerialFrame->setMidLineWidth(0);
        verticalLayoutWidget = new QWidget(SerialFrame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 371, 301));
        SerialLeyout = new QVBoxLayout(verticalLayoutWidget);
        SerialLeyout->setSpacing(6);
        SerialLeyout->setContentsMargins(11, 11, 11, 11);
        SerialLeyout->setObjectName(QStringLiteral("SerialLeyout"));
        SerialLeyout->setSizeConstraint(QLayout::SetMaximumSize);
        SerialLeyout->setContentsMargins(0, 0, 0, 0);
        cubeFrame = new QFrame(centralWidget);
        cubeFrame->setObjectName(QStringLiteral("cubeFrame"));
        cubeFrame->setGeometry(QRect(394, 9, 500, 568));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cubeFrame->sizePolicy().hasHeightForWidth());
        cubeFrame->setSizePolicy(sizePolicy1);
        cubeFrame->setMinimumSize(QSize(500, 500));
        cubeFrame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        cubeFrame->setFrameShape(QFrame::Box);
        cubeFrame->setFrameShadow(QFrame::Raised);
        cubeFrame->setLineWidth(3);
        graphFrame = new QFrame(centralWidget);
        graphFrame->setObjectName(QStringLiteral("graphFrame"));
        graphFrame->setGeometry(QRect(9, 296, 370, 281));
        graphFrame->setFrameShape(QFrame::StyledPanel);
        graphFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_2 = new QWidget(graphFrame);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 101, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        accx = new QLCDNumber(verticalLayoutWidget_2);
        accx->setObjectName(QStringLiteral("accx"));
        accx->setSmallDecimalPoint(false);
        accx->setDigitCount(7);
        accx->setProperty("value", QVariant(0));

        verticalLayout->addWidget(accx);

        accy = new QLCDNumber(verticalLayoutWidget_2);
        accy->setObjectName(QStringLiteral("accy"));
        accy->setSmallDecimalPoint(false);
        accy->setDigitCount(3);

        verticalLayout->addWidget(accy);

        accz = new QLCDNumber(verticalLayoutWidget_2);
        accz->setObjectName(QStringLiteral("accz"));
        accz->setDigitCount(3);

        verticalLayout->addWidget(accz);

        horizontalLayoutWidget = new QWidget(graphFrame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 180, 369, 59));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pwm_1 = new QLCDNumber(horizontalLayoutWidget);
        pwm_1->setObjectName(QStringLiteral("pwm_1"));
        pwm_1->setDigitCount(4);

        horizontalLayout->addWidget(pwm_1);

        pwm_2 = new QLCDNumber(horizontalLayoutWidget);
        pwm_2->setObjectName(QStringLiteral("pwm_2"));
        pwm_2->setDigitCount(4);

        horizontalLayout->addWidget(pwm_2);

        pwm_3 = new QLCDNumber(horizontalLayoutWidget);
        pwm_3->setObjectName(QStringLiteral("pwm_3"));
        pwm_3->setDigitCount(4);

        horizontalLayout->addWidget(pwm_3);

        pwm_4 = new QLCDNumber(horizontalLayoutWidget);
        pwm_4->setObjectName(QStringLiteral("pwm_4"));
        pwm_4->setDigitCount(4);

        horizontalLayout->addWidget(pwm_4);

        horizontalLayoutWidget_2 = new QWidget(graphFrame);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 240, 371, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setLayoutDirection(Qt::RightToLeft);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_4);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setLayoutDirection(Qt::RightToLeft);
        lineEdit_3->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setLayoutDirection(Qt::RightToLeft);
        lineEdit_2->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setLayoutDirection(Qt::RightToLeft);
        lineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit);

        line_2 = new QFrame(graphFrame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 160, 371, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(390, 580, 1038, 291));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalSlider_1 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_1->setObjectName(QStringLiteral("verticalSlider_1"));
        verticalSlider_1->setMaximum(1000);
        verticalSlider_1->setOrientation(Qt::Vertical);
        verticalSlider_1->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_1);

        verticalSlider_2 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setMaximum(1000);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_2->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_2);

        verticalSlider_3 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setMaximum(1000);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_3->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_3);

        verticalSlider_4 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_4->setObjectName(QStringLiteral("verticalSlider_4"));
        verticalSlider_4->setMaximum(1000);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_4->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_4);

        verticalSlider_5 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_5->setObjectName(QStringLiteral("verticalSlider_5"));
        verticalSlider_5->setMaximum(1000);
        verticalSlider_5->setOrientation(Qt::Vertical);
        verticalSlider_5->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_5);

        verticalSlider_6 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_6->setObjectName(QStringLiteral("verticalSlider_6"));
        verticalSlider_6->setMaximum(1000);
        verticalSlider_6->setOrientation(Qt::Vertical);
        verticalSlider_6->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_6);

        verticalSlider_7 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_7->setObjectName(QStringLiteral("verticalSlider_7"));
        verticalSlider_7->setMaximum(1000);
        verticalSlider_7->setOrientation(Qt::Vertical);
        verticalSlider_7->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_7);

        verticalSlider_8 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_8->setObjectName(QStringLiteral("verticalSlider_8"));
        verticalSlider_8->setMaximum(1000);
        verticalSlider_8->setOrientation(Qt::Vertical);
        verticalSlider_8->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_8);

        verticalSlider_9 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_9->setObjectName(QStringLiteral("verticalSlider_9"));
        verticalSlider_9->setMaximum(1000);
        verticalSlider_9->setOrientation(Qt::Vertical);
        verticalSlider_9->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_9);

        verticalSlider_10 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_10->setObjectName(QStringLiteral("verticalSlider_10"));
        verticalSlider_10->setMaximum(1000);
        verticalSlider_10->setOrientation(Qt::Vertical);
        verticalSlider_10->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_10);

        verticalSlider_11 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_11->setObjectName(QStringLiteral("verticalSlider_11"));
        verticalSlider_11->setMaximum(1000);
        verticalSlider_11->setOrientation(Qt::Vertical);
        verticalSlider_11->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_11);

        verticalSlider_12 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_12->setObjectName(QStringLiteral("verticalSlider_12"));
        verticalSlider_12->setMaximum(1000);
        verticalSlider_12->setOrientation(Qt::Vertical);
        verticalSlider_12->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_12);

        verticalSlider_13 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_13->setObjectName(QStringLiteral("verticalSlider_13"));
        verticalSlider_13->setMaximum(1000);
        verticalSlider_13->setOrientation(Qt::Vertical);
        verticalSlider_13->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_13);

        verticalSlider_14 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_14->setObjectName(QStringLiteral("verticalSlider_14"));
        verticalSlider_14->setMaximum(1000);
        verticalSlider_14->setOrientation(Qt::Vertical);
        verticalSlider_14->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_14);

        verticalSlider_15 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_15->setObjectName(QStringLiteral("verticalSlider_15"));
        verticalSlider_15->setMaximum(1000);
        verticalSlider_15->setOrientation(Qt::Vertical);
        verticalSlider_15->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_15);

        verticalSlider_16 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_16->setObjectName(QStringLiteral("verticalSlider_16"));
        verticalSlider_16->setMaximum(1000);
        verticalSlider_16->setOrientation(Qt::Vertical);
        verticalSlider_16->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_16);

        verticalSlider_17 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_17->setObjectName(QStringLiteral("verticalSlider_17"));
        verticalSlider_17->setMaximum(1000);
        verticalSlider_17->setOrientation(Qt::Vertical);
        verticalSlider_17->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_17);

        verticalSlider_18 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_18->setObjectName(QStringLiteral("verticalSlider_18"));
        verticalSlider_18->setMaximum(1000);
        verticalSlider_18->setOrientation(Qt::Vertical);
        verticalSlider_18->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_18);

        verticalSlider_19 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_19->setObjectName(QStringLiteral("verticalSlider_19"));
        verticalSlider_19->setMaximum(1000);
        verticalSlider_19->setOrientation(Qt::Vertical);
        verticalSlider_19->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_19);

        verticalSlider_20 = new QSlider(verticalLayoutWidget_3);
        verticalSlider_20->setObjectName(QStringLiteral("verticalSlider_20"));
        verticalSlider_20->setMaximum(1000);
        verticalSlider_20->setTracking(true);
        verticalSlider_20->setOrientation(Qt::Vertical);
        verticalSlider_20->setInvertedAppearance(false);
        verticalSlider_20->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(verticalSlider_20);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lcdNumber_1 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_1->setObjectName(QStringLiteral("lcdNumber_1"));
        lcdNumber_1->setDigitCount(3);
        lcdNumber_1->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_1);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setDigitCount(3);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_2);

        lcdNumber_3 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setDigitCount(3);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_3);

        lcdNumber_4 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setDigitCount(3);
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_4);

        lcdNumber_5 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_5->setObjectName(QStringLiteral("lcdNumber_5"));
        lcdNumber_5->setDigitCount(3);
        lcdNumber_5->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_5);

        lcdNumber_6 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_6->setObjectName(QStringLiteral("lcdNumber_6"));
        lcdNumber_6->setDigitCount(3);
        lcdNumber_6->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_6);

        lcdNumber_7 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_7->setObjectName(QStringLiteral("lcdNumber_7"));
        lcdNumber_7->setDigitCount(3);
        lcdNumber_7->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_7);

        lcdNumber_8 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_8->setObjectName(QStringLiteral("lcdNumber_8"));
        lcdNumber_8->setDigitCount(3);
        lcdNumber_8->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_8);

        lcdNumber_9 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_9->setObjectName(QStringLiteral("lcdNumber_9"));
        lcdNumber_9->setDigitCount(3);
        lcdNumber_9->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_9);

        lcdNumber_10 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_10->setObjectName(QStringLiteral("lcdNumber_10"));
        lcdNumber_10->setDigitCount(3);
        lcdNumber_10->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_10);

        lcdNumber_11 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_11->setObjectName(QStringLiteral("lcdNumber_11"));
        lcdNumber_11->setDigitCount(3);
        lcdNumber_11->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_11);

        lcdNumber_12 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_12->setObjectName(QStringLiteral("lcdNumber_12"));
        lcdNumber_12->setDigitCount(3);
        lcdNumber_12->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_12);

        lcdNumber_13 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_13->setObjectName(QStringLiteral("lcdNumber_13"));
        lcdNumber_13->setDigitCount(3);
        lcdNumber_13->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_13);

        lcdNumber_14 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_14->setObjectName(QStringLiteral("lcdNumber_14"));
        lcdNumber_14->setDigitCount(3);
        lcdNumber_14->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_14);

        lcdNumber_15 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_15->setObjectName(QStringLiteral("lcdNumber_15"));
        lcdNumber_15->setDigitCount(3);
        lcdNumber_15->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_15);

        lcdNumber_16 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_16->setObjectName(QStringLiteral("lcdNumber_16"));
        lcdNumber_16->setDigitCount(3);
        lcdNumber_16->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_16);

        lcdNumber_17 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_17->setObjectName(QStringLiteral("lcdNumber_17"));
        lcdNumber_17->setDigitCount(3);
        lcdNumber_17->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_17);

        lcdNumber_18 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_18->setObjectName(QStringLiteral("lcdNumber_18"));
        lcdNumber_18->setDigitCount(3);
        lcdNumber_18->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_18);

        lcdNumber_19 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_19->setObjectName(QStringLiteral("lcdNumber_19"));
        lcdNumber_19->setDigitCount(3);
        lcdNumber_19->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_19);

        lcdNumber_20 = new QLCDNumber(verticalLayoutWidget_3);
        lcdNumber_20->setObjectName(QStringLiteral("lcdNumber_20"));
        lcdNumber_20->setDigitCount(3);
        lcdNumber_20->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_6->addWidget(lcdNumber_20);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(130, 670, 251, 54));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_7->addLayout(horizontalLayout_5);

        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_7->addWidget(label);

        savecurve = new QPushButton(centralWidget);
        savecurve->setObjectName(QStringLiteral("savecurve"));
        savecurve->setGeometry(QRect(20, 680, 75, 23));
        savecurve->setCheckable(false);
        loadcurve = new QPushButton(centralWidget);
        loadcurve->setObjectName(QStringLiteral("loadcurve"));
        loadcurve->setGeometry(QRect(20, 710, 75, 23));
        loadcurve->setCheckable(true);
        derivativeweight = new QDoubleSpinBox(centralWidget);
        derivativeweight->setObjectName(QStringLiteral("derivativeweight"));
        derivativeweight->setGeometry(QRect(100, 580, 62, 22));
        derivativeweight->setMinimum(-1000);
        derivativeweight->setMaximum(1000);
        derivativeweight->setSingleStep(0.01);
        story_point_num = new QSpinBox(centralWidget);
        story_point_num->setObjectName(QStringLiteral("story_point_num"));
        story_point_num->setGeometry(QRect(20, 790, 61, 22));
        story_point_num->setMaximum(600);
        story_point_num->setValue(10);
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(20, 580, 75, 23));
        proportionalweight = new QDoubleSpinBox(centralWidget);
        proportionalweight->setObjectName(QStringLiteral("proportionalweight"));
        proportionalweight->setGeometry(QRect(280, 580, 62, 22));
        proportionalweight->setMinimum(-1000);
        proportionalweight->setMaximum(1000);
        proportionalweight->setSingleStep(0.01);
        integrativeweight = new QDoubleSpinBox(centralWidget);
        integrativeweight->setObjectName(QStringLiteral("integrativeweight"));
        integrativeweight->setGeometry(QRect(190, 580, 62, 22));
        integrativeweight->setMinimum(-1000);
        integrativeweight->setMaximum(1000);
        integrativeweight->setSingleStep(0.01);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(160, 580, 21, 31));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(250, 580, 21, 31));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(340, 580, 21, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 911, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple Terminal", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "PWM_1", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "PWM_2", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "PWM_3", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "PWM_4", 0));
        pushButton->setText(QApplication::translate("MainWindow", "SeT Curve", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        savecurve->setText(QApplication::translate("MainWindow", "Save Curve", 0));
        loadcurve->setText(QApplication::translate("MainWindow", "Load Curve", 0));
        stop->setText(QApplication::translate("MainWindow", "PANIC!!!", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D</span></p></body></html>", 0));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">I</span></p></body></html>", 0));
        textEdit_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">P</span></p></body></html>", 0));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

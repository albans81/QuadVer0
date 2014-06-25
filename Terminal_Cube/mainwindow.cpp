/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "mainwidget.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new Console(ui->SerialFrame);
    ui->SerialLeyout->addWidget(console);
    console->setObjectName("Terminale");
    console->setEnabled(false);
    console->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //console->setGeometry(0,0,300,400);//qui ti ci spassi
    console->adjustSize();

    Pwm_value = 0;
    indice_acc = 0;
    dev_accy = 0;

    serial   = new QSerialPort(this);
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    pCubeWidget = new MainWidget(ui->cubeFrame);
    pCubeWidget->setGeometry(0,0,ui->cubeFrame->width(),ui->cubeFrame->height());


    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(pid_control()));
    //connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    if (serial->open(QIODevice::ReadWrite)) {
        if (serial->setBaudRate(p.baudRate)
                && serial->setDataBits(p.dataBits)
                && serial->setParity(p.parity)
                && serial->setStopBits(p.stopBits)
                && serial->setFlowControl(p.flowControl)) {

            console->setEnabled(true);
            console->setLocalEchoEnabled(p.localEchoEnabled);
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

        } else {
            serial->close();
            QMessageBox::critical(this, tr("Error"), serial->errorString());

            ui->statusBar->showMessage(tr("Open error"));
        }
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Configure error"));
    }
}

void MainWindow::closeSerialPort()
{
    serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

QString MainWindow::HexToAscii(QString String)

{

    QByteArray ByteArray1=String.toUtf8();

    const char* chArr1=ByteArray1.constData();

    QByteArray ByteArray2=QByteArray::fromHex(chArr1);

    const char* chArr2=ByteArray2.constData();

    return QString::fromUtf8(chArr2);

}

QString MainWindow::AsciiToHex(QString String)

{

    QByteArray ByteArray1=String.toUtf8();

    QByteArray ByteArray2=ByteArray1.toHex();

    const char* chArr1=ByteArray2.constData();

    return QString::fromUtf8(chArr1);

}

void MainWindow::pid_control()
{
    double tmp = 0;
    double tmp_ist = 0;
    int accy = ui->accy->value();
    if (abs(accy) > 45){
        tmp = 0.6;
    } else if (abs(accy) <= 45 && abs(accy) > 30){
        tmp = 0.4;
    } else if (abs(accy) <= 30 && abs(accy) > 20){
        tmp = 0.1;
    } else if (abs(accy) <= 20 && abs(accy) > 15){
        tmp = 0.06;
    }else if (abs(accy) <= 15 && abs(accy) > 11){
        tmp = 0.03;
    }else if (abs(accy) <= 11 && abs(accy) > 8){
        tmp = 0.01;
    }else if (abs(accy) <= 8 && abs(accy) > 5){
        tmp = 0.005;
    }

    int accy_ist = in[2];
    if (abs(accy_ist + dev_accy*1.2) > 45){
        tmp_ist = 0.6;
    }else if (abs(accy_ist + dev_accy*2) <= 45 && abs(accy_ist) > 30){
        tmp_ist = 0.4;
    }else if (abs(accy_ist + dev_accy*2) <= 30 && abs(accy_ist) > 20){
        tmp_ist = 0.1;
    }else if (abs(accy_ist + dev_accy*2) <= 20 && abs(accy_ist) > 15){
        tmp_ist = 0.06;
    }else if (abs(accy_ist + dev_accy*2) <= 15 && abs(accy_ist) > 11){
        tmp_ist = 0.03;
    }else if (abs(accy_ist + dev_accy*2) <= 11 && abs(accy_ist) > 8){
        tmp_ist = 0.01;
    }else if (abs(accy_ist + dev_accy*2) <= 8 && abs(accy_ist) > 5){
        tmp_ist = 0.005;
    }
    tmp = (tmp+tmp_ist)/2;
    if (accy > 0 && (unsigned int) Pwm_value < 2000)
        Pwm_value = Pwm_value + tmp;
    else if (accy < 0 && (unsigned int)Pwm_value > 1100)
        Pwm_value = Pwm_value - tmp;

    QByteArray rr;
    rr.append((quint16)Pwm_value);
    rr.append(((quint16)Pwm_value)>>8);
    writeData(rr);
}

void MainWindow::readData()
{    
    int med_accy = 0;
    in = serial->readAll();
    //console->putData(in.toHex());
    ui->accx->display(in[0]);
    pCubeWidget->rotation = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), in[2]);
    //updateGL();
    mdv[indice_acc] = in[2];
    indice_acc++;
    if (indice_acc == 10)
        indice_acc = 0;
    for (int i = 0; i < 10; i++){
        med_accy += mdv[i];
        int k = indice_acc+i;
        if (k >= 10)
            k = k - 10;
        if ( k == 0)
            k = 9;
        dev_accy += in[2] - mdv[k];
    }
    dev_accy = dev_accy/10;
    med_accy = med_accy/10;
    ui->accy->display(med_accy);
    pCubeWidget->rotation *= QQuaternion::fromAxisAndAngle(QVector3D(0,0,1), in[0]);
    ui->accz->display(dev_accy);    //in[4]);
    int tmp;
    tmp = (quint16)in[7] << 8;
    tmp = tmp + (quint8)in[6];
    if (Pwm_value == 0)
        Pwm_value = tmp;
    ui->pwm_1->display(tmp);
    //in.clear();
    //in.append(13);
    //console->putData(in);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

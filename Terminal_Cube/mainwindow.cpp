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
#include <QFileDialog>

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QScrollArea>

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
    throttle = 1160;
    IntValue = 0;
    indice_acc = 0;
    last_accy = 0;
    dev_accy = 0;
    dev_weight = 0.20;
    Pro_weight = 0.81;
    Int_weight = 0.46;
    story_point = 10;
    last_derivative = 0;
    /// Low pass filter cut frequency for derivative calculation.
    ///
    filter = 7.9577e-3; // Set to  "1 / ( 2 * PI * f_cut )";
    // Examples for _filter:
    // f_cut = 10 Hz -> _filter = 15.9155e-3
    // f_cut = 15 Hz -> _filter = 10.6103e-3
    // f_cut = 20 Hz -> _filter =  7.9577e-3
    // f_cut = 25 Hz -> _filter =  6.3662e-3
    // f_cut = 30 Hz -> _filter =  5.3052e-3


    /* Setting graph_value ed set pot */
    ui->derivativeweight->setValue(dev_weight);
    ui->integrativeweight->setValue(Int_weight);
    ui->proportionalweight->setValue(Pro_weight);
    for (int i = 0; i < 20; i++)
        graph_value[i] = i;
    setsliderpos();

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
    connect(ui->savecurve,SIGNAL(clicked()),this,SLOT(save_curve()));
    connect(ui->loadcurve,SIGNAL(clicked()),this,SLOT(load_curve()));
    connect(ui->stop,SIGNAL(clicked()),this,SLOT(stop()));
    connect(ui->story_point_num,SIGNAL(valueChanged(int)),this,SLOT(story_point_set()));
    connect(ui->derivativeweight,SIGNAL(valueChanged(double)),this,SLOT(set_derivativeweight()));
    connect(ui->integrativeweight,SIGNAL(valueChanged(double)),this,SLOT(set_integrativeweight()));
    connect(ui->proportionalweight,SIGNAL(valueChanged(double)),this,SLOT(set_proportionalweight()));
    connect(ui->verticalSlider_1,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_9,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_10,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_11,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_12,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_13,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_14,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_15,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_16,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_17,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_18,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_19,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_20,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    //connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));

    //QScrollArea* scrollArea = new QScrollArea(this);
    //scrollArea->set
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}
void MainWindow::setsliderpos()
{
    disconnect(ui->verticalSlider_1,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_9,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_10,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_11,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_12,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_13,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_14,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_15,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_16,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_17,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_18,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_19,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    disconnect(ui->verticalSlider_20,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));


    ui->verticalSlider_1->setValue((int)graph_value[0]);
    ui->verticalSlider_2->setValue((int)graph_value[1]);
    ui->verticalSlider_3->setValue((int)graph_value[2]);
    ui->verticalSlider_4->setValue((int)graph_value[3]);
    ui->verticalSlider_5->setValue((int)graph_value[4]);
    ui->verticalSlider_6->setValue((int)graph_value[5]);
    ui->verticalSlider_7->setValue((int)graph_value[6]);
    ui->verticalSlider_8->setValue((int)graph_value[7]);
    ui->verticalSlider_9->setValue((int)graph_value[8]);
    ui->verticalSlider_10->setValue((int)graph_value[9]);
    ui->verticalSlider_11->setValue((int)graph_value[10]);
    ui->verticalSlider_12->setValue((int)graph_value[11]);
    ui->verticalSlider_13->setValue((int)graph_value[12]);
    ui->verticalSlider_14->setValue((int)graph_value[13]);
    ui->verticalSlider_15->setValue((int)graph_value[14]);
    ui->verticalSlider_16->setValue((int)graph_value[15]);
    ui->verticalSlider_17->setValue((int)graph_value[16]);
    ui->verticalSlider_18->setValue((int)graph_value[17]);
    ui->verticalSlider_19->setValue((int)graph_value[18]);
    ui->verticalSlider_20->setValue((int)graph_value[19]);

    reflesh_slider_value();

    connect(ui->verticalSlider_1,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_9,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_10,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_11,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_12,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_13,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_14,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_15,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_16,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_17,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_18,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_19,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
    connect(ui->verticalSlider_20,SIGNAL(valueChanged(int)),this,SLOT(reflesh_slider_value()));
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
void MainWindow::reflesh_slider_value()
{
    ui->lcdNumber_1->display(ui->verticalSlider_1->value());
    graph_value[0] = ui->verticalSlider_1->value();
    ui->lcdNumber_2->display(ui->verticalSlider_2->value());
    graph_value[1] = ui->verticalSlider_2->value();
    ui->lcdNumber_3->display(ui->verticalSlider_3->value());
    graph_value[2] = ui->verticalSlider_3->value();
    ui->lcdNumber_4->display(ui->verticalSlider_4->value());
    graph_value[3] = ui->verticalSlider_4->value();
    ui->lcdNumber_5->display(ui->verticalSlider_5->value());
    graph_value[4] = ui->verticalSlider_5->value();
    ui->lcdNumber_6->display(ui->verticalSlider_6->value());
    graph_value[5] = ui->verticalSlider_6->value();
    ui->lcdNumber_7->display(ui->verticalSlider_7->value());
    graph_value[6] = ui->verticalSlider_7->value();
    ui->lcdNumber_8->display(ui->verticalSlider_8->value());
    graph_value[7] = ui->verticalSlider_8->value();
    ui->lcdNumber_9->display(ui->verticalSlider_9->value());
    graph_value[8] = ui->verticalSlider_9->value();
    ui->lcdNumber_10->display(ui->verticalSlider_10->value());
    graph_value[9] = ui->verticalSlider_10->value();
    ui->lcdNumber_11->display(ui->verticalSlider_11->value());
    graph_value[10] = ui->verticalSlider_11->value();
    ui->lcdNumber_12->display(ui->verticalSlider_12->value());
    graph_value[11] = ui->verticalSlider_12->value();
    ui->lcdNumber_13->display(ui->verticalSlider_13->value());
    graph_value[12] = ui->verticalSlider_13->value();
    ui->lcdNumber_14->display(ui->verticalSlider_14->value());
    graph_value[13] = ui->verticalSlider_14->value();
    ui->lcdNumber_15->display(ui->verticalSlider_15->value());
    graph_value[14] = ui->verticalSlider_15->value();
    ui->lcdNumber_16->display(ui->verticalSlider_16->value());
    graph_value[15] = ui->verticalSlider_16->value();
    ui->lcdNumber_17->display(ui->verticalSlider_17->value());
    graph_value[16] = ui->verticalSlider_17->value();
    ui->lcdNumber_18->display(ui->verticalSlider_18->value());
    graph_value[17] = ui->verticalSlider_18->value();
    ui->lcdNumber_19->display(ui->verticalSlider_19->value());
    graph_value[18] = ui->verticalSlider_19->value();
    ui->lcdNumber_20->display(ui->verticalSlider_20->value());
    graph_value[19] = ui->verticalSlider_20->value();
}

void MainWindow::set_derivativeweight()
{
    dev_weight = ui->derivativeweight->value();
}

void MainWindow::set_integrativeweight()
{
    Int_weight = ui->integrativeweight->value();
}

void MainWindow::set_proportionalweight()
{
    Pro_weight = ui->proportionalweight->value();
}

void MainWindow::save_curve()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "untitled.dat",
                                tr("dataraw (*.dat)"));
    QFile *fp = new QFile (fileName);
    fp->open(QFile::WriteOnly);
    fp->write((char*)graph_value,sizeof(graph_value));
    fp->close();
}
void MainWindow::story_point_set()
{
    story_point = ui->story_point_num->value();
}

void MainWindow::load_curve()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/",
                                                     tr("dataraw (*.dat)"));
    QFile *fp = new QFile (fileName);
    fp->open(QFile::ReadOnly);
    fp->read((char*)graph_value,sizeof(graph_value));
    fp->close();
    setsliderpos();

}

void MainWindow::stop(){
    disconnect(serial, SIGNAL(readyRead()), this, SLOT(pid_control()));
    double Pwm_stop = 1000;
    QByteArray rr;
    rr.append((quint16)Pwm_stop);
    rr.append(((quint16)Pwm_stop)>>8);
    rr.append((quint16)Pwm_stop);
    rr.append(((quint16)Pwm_stop)>>8);
    writeData(rr);    
}
                          ////PID///////////////////////////////////////

void MainWindow::pid_control()
{
    double tmp = 0;
    double tmp2 = 0;

    int accy_ist = in[2]; // volendo avere angolo 0 questo rappresenta il nostro errore
    // in[2] è il valore ricevuto dal mems
    //Calcolo del termine integrale
    float deltatime = 10.0/1000.0;
    IntValue += accy_ist * deltatime;
    // TODO da fare la limitazione (Windup)

    // Calcolo termine derivativo
    float dTerm = dev_weight * (accy_ist - last_accy) / (deltatime * 100); //
    /*
    dTerm = last_derivative +
                 (deltatime / (filter + deltatime)) * (dTerm - last_derivative);
    last_derivative = dTerm;
*/
    // TODO aggiungere un filtro passa basso per eliminare i disturbi dovuti alle vobrazioni del motore
    last_accy = accy_ist;


    double PID_Value = (Pro_weight * accy_ist) + (IntValue * Int_weight) + dTerm;
    ui->accx->display(PID_Value);

    tmp2 = throttle + PID_Value;
    tmp = throttle - PID_Value;


    QByteArray rr;
    rr.append((quint16)tmp2);
    rr.append(((quint16)tmp2)>>8);
    rr.append((quint16)tmp);
    rr.append(((quint16)tmp)>>8);
    writeData(rr);


}

void MainWindow::pid_control_lavendetta()
{
    double tmp = 0;
    double tmp_ist = 0;
    int accy = ui->accy->value();
    int pos = (abs(accy))/2;
    if (pos > 19 && pos < 80)
        pos = 19;
    else if (pos > 80)
        pos = 0;
    tmp = (graph_value[pos])/1000;
    /*
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
    */
    int accy_ist = in[2];
    pos = (abs(accy_ist + dev_accy*dev_weight))/2;
    if (pos > 19 && pos < 80)
        pos = 19;
    else if (pos > 80)
        pos = 0;
    tmp_ist = (graph_value[pos])/1000;

    /*
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
    */
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
    //ui->accx->display(in[0]);
    pCubeWidget->rotation = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), in[2]);
    //updateGL();


    mdv[indice_acc] = in[2];
    indice_acc++;
    if (indice_acc == story_point)
        indice_acc = 0;
    for (int i = 0; i < story_point; i++){
        med_accy += mdv[i];
        int k = indice_acc+i;
        if (k >= story_point)
            k = k - story_point;
        if ( k == 0)
            k = story_point - 1;
        dev_accy += in[2] - mdv[k];
    }
    dev_accy = dev_accy/story_point;
    med_accy = med_accy/story_point;
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

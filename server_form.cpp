#include <QCoreApplication>
#include <QTextCodec>
#include "tcpServerClass.h"
#include <QCommandLineParser>
#include <QDebug>
#include "server_form.h"
#include "ui_server_form.h"
#include "ui3280player.h"
#pragma execution_character_set("utf-8")
#include <QFile>
#include <QTextStream>

Server_Form::Server_Form(QWidget *parent) : QDialog(parent), ui(new Ui::Server_Form)
{
    ui->setupUi(this);
    this->initForm();

}

Server_Form::~Server_Form()
{
    delete ui;
}

bool Server_Form::eventFilter(QObject *watched, QEvent *event)
{

    return QWidget::eventFilter(watched, event);
}


void Server_Form::initForm()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setProperty("canMove", true);

}



void Server_Form::on_buttonBox_rejected()
{
    this->close();
}

void Server_Form::on_buttonBox_accepted()
{



     int portNum = ui->port_input->text().toInt();
     QString fileName = ui->port_input_2->text();


     ui->label->setText("After all we have port="+QString::number(portNum)+" and fileName: "+fileName);
     QFile qf(fileName );

     if(!qf.exists()) {
         ui->label->setText("File seems to not exists. Can not proceed");
         qDebug()<<"File "<<fileName<<"  seems to not exists. Can not proceed";
     }
     if (!qf.open(QIODevice::ReadOnly | QIODevice::Text)) {
         qDebug()<<"Faild to open File "<<fileName<<". Can not proceed";

     }
     std::list<__FileRec> db;
     QTextStream in(&qf);
     while (!in.atEnd()) {
           __FileRec fr;
           in>>fr.id>>fr.filePath;
           db.push_back(fr);
     }
    QObject dummy;
    TCPServerClass m( portNum, db, &dummy);
     connect(this, SIGNAL(fire()),&m,SLOT(run()));
     connect(this, SIGNAL(dis_clicked()),&m,SLOT(discon()));
    //QObject::connect(&m, SIGNAL(finished()), this, SLOT(quit()));

   emit fire();

     ui->label->setText("Connected");
      this->exec();
    qDebug()<<"a.exec() exited";

}

void Server_Form::on_disconnect_btn_clicked()
{
    emit dis_clicked();
}

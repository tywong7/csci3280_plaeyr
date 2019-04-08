#include "client_form.h"
#include "ui_client_form.h"
#include <QCoreApplication>
#include <QTextCodec>
#include <QCommandLineParser>
#include <QDebug>
#include <QFile>
#include "interleave.h"
#pragma execution_character_set("utf-8")
#include <QFile>
#include <QTextStream>
QStringList  Client_Form::textfile;
Client_Form::Client_Form(QWidget *parent) : QDialog(parent), ui(new Ui::Client_Form)
{
    ui->setupUi(this);
    this->initForm();

}

Client_Form::~Client_Form()
{
    delete ui;
}

bool Client_Form::eventFilter(QObject *watched, QEvent *event)
{

    return QWidget::eventFilter(watched, event);
}


void Client_Form::initForm()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setProperty("canMove", true);
     ui->label_4->setText("Status:");

}



void Client_Form::on_buttonBox_rejected()
{
    this->close();
}

void Client_Form::on_buttonBox_accepted()
{

    std::list<__sourceDefine> db;
    __sourceDefine test;
    test.srcType=__sourceDefine::REMOTE;
    test.path=this->ui->ip_input->text();
    test.port=this->ui->port_input->text().toUInt();
    test.remoteId=this->ui->remoteid_input->text().toUInt();
    db.push_back(test);
    qDebug()<<test.port;
    QString outFileName=test.path+"_db.txt";
    QObject static tesdt;
    multiPointReceiver m(&tesdt);
    m.setSources(db);

    char buff[4000];
    qint64 rv;
    QFile outF(outFileName);
    if (!outF.open(QIODevice::WriteOnly )) {
        ui->label_4->setText("Status:Faild to open File :"+outFileName+". Can not proceed");


    }

    qDebug()<<"File is "<<m.getObjectSize()<<"  bytes long";


    qint64 total = 0;
    while((rv=m.getDataToBufferFromOffset(buff, 4000, total))> 0) {
        outF.write(buff, rv);
        total += rv;
    }

    outF.close();
    ui->label_4->setText("Status:Done");
    textfile.clear();

    QString fullpath = test.path+"_db.txt";
    QFile file(fullpath);
    if (!file.exists()) {
        qDebug()<<"database not found.";
        return;
    }
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!file.atEnd()){
        textfile.append(file.readLine());
    }
    for (int i=0;i<Client_Form::textfile.length();i++){

        qDebug()<<Client_Form::textfile[i].split(",").at(1);

    }
    emit loaded();
    qDebug()<<"a.exec() exited";
}

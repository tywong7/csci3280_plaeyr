#include "edit_form.h"
#include "ui_edit_form.h"
#include "iconhelper.h"
#include "flatui.h"
#include "ui3280player.h"
#pragma execution_character_set("utf-8")
#include <QFile>
#include <QTextStream>

Edit_Form::Edit_Form(QWidget *parent) : QDialog(parent), ui(new Ui::Edit_Form)
{
    ui->setupUi(this);
    this->initForm();

}

Edit_Form::~Edit_Form()
{
    delete ui;
}

bool Edit_Form::eventFilter(QObject *watched, QEvent *event)
{

    return QWidget::eventFilter(watched, event);
}


void Edit_Form::initForm()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setProperty("canMove", true);
    this->ui->singer_input->setText(UI3280Player::singerlist[UI3280Player::index]);
    this->ui->song_input->setText(UI3280Player::songnamelist[UI3280Player::index]);
    this->ui->abum_input->setText(UI3280Player::albumlist[UI3280Player::index]);
}



void Edit_Form::on_buttonBox_rejected()
{
    this->close();
}

void Edit_Form::on_buttonBox_accepted()
{
    UI3280Player::singerlist[UI3280Player::index]=this->ui->singer_input->text();

     UI3280Player::songnamelist[UI3280Player::index]=this->ui->song_input->text();
     UI3280Player::albumlist[UI3280Player::index]=this->ui->abum_input->text();
     QString fullpath =  "music_database.txt";
     QFile file(fullpath);
     if (!file.exists()) {
         qDebug()<<"database not found.";
         return;
     }
     if (file.open(QIODevice::WriteOnly|QFile::Truncate)) {
            QTextStream stream(&file);
            QString output;
            for (int i=0;i< UI3280Player::songnamelist.length();i++){

                 output=UI3280Player::pathlist[i]+","+UI3280Player::songnamelist[i]+","+UI3280Player::singerlist[i]+","+UI3280Player::albumlist[i];
                 stream << output;
            }
     }
     file.close();
     this->close();
}

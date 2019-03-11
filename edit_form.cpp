#include "edit_form.h"
#include "ui_edit_form.h"
#include "iconhelper.h"
#include "flatui.h"
#include "ui3280player.h"
#pragma execution_character_set("utf-8")
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
    this->ui->singer_input->setText(UI3280Player::a);
}



void Edit_Form::on_buttonBox_rejected()
{
    this->close();
}

void Edit_Form::on_buttonBox_accepted()
{
    printf("ok");
    this->close();
}

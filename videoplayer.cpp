#include "videoplayer.h"
#include "ui_videoplayer.h"
#include "iconhelper.h"
#include "flatui.h"
#include "ui3280player.h"
videoplayer::videoplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::videoplayer)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    wid=new QVideoWidget(this);
    player->setVideoOutput(wid);
    ui->container->addWidget(wid);
    this->initForm();
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(getDuration(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(checkPosition(qint64)));


}

videoplayer::~videoplayer()
{
    delete ui;
}

bool static videomax=false;
bool videoplayer::vp_playing=false;
int videoplayer::vp_vol=0;
qint64 videoplayer:: vp_duration=1;
qint64 videoplayer:: vp_current=1;
qint64 videoplayer:: vp_userslided=0;
qint64 videoplayer:: vp_durationval=1;
QString videoplayer:: totalTime="";
QString videoplayer:: nowTime="";

bool videoplayer::eventFilter(QObject *watched, QEvent *event)
{
if (watched == ui->vp_top && event->type() == QEvent::MouseButtonDblClick) {


    if (!videomax)
        showMaximized();
    else showNormal();
    videomax=!videomax;
    return true;
    }
return QWidget::eventFilter(watched, event);
}



void videoplayer::initForm()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setProperty("canMove", true);
    IconHelper::Instance()->setIcon(ui->btn_file, QChar(0xf07b), 12);
    IconHelper::Instance()->setIcon(ui->btn_close, QChar(0xf00d), 12);
    ui->vp_top->installEventFilter(this);

}

void videoplayer::on_btn_close_clicked()
{

    this->close();

    vp_stopcontrol();
    emit vi_stop();
}

void videoplayer::checkPosition(qint64 x)
{

    QTime displayTime(0, (x / 60000) % 60, (x / 1000) % 60,0);
    int min=(x / 60000)% 60;
    int sec=((x / 1000) % 60);
    nowTime= QString("%1").arg(min,2,10,QChar('0'))+":"+QString("%1").arg(sec,2,10,QChar('0'));

    int now= min*60+sec;

    vp_current=(now*100/vp_duration);
    qDebug()<<vp_current;
    emit sliderwork();
}
void videoplayer::slider_changed(){
   player->setPosition(vp_userslided);
   player->play();
}
void videoplayer::getDuration(qint64 x)
{
    qDebug()<<"duration";
    totalTime= QString("%1").arg((x / 60000)% 60,2,10,QChar('0'))+":"+QString("%1").arg(((x / 1000) % 60),2,10,QChar('0'));
    vp_durationval=x;

    vp_duration=(x / 60000)% 60*60+((x / 1000) % 60);
    qDebug()<<vp_duration;

    if (!player->isVideoAvailable())
        this->resize(740,50);
    else this->resize(740,569);

}
void videoplayer::on_btn_file_clicked()
{

    QString filename= QFileDialog::getOpenFileName(this,"Open a file","*.*","Media File(*.wmv, *.mp3)");
    player->setMedia((QUrl::fromLocalFile(filename)));
    vp_duration=1;
    vp_current=1;
    vp_userslided=0;
    vp_durationval=1;

    UI3280Player::playing=true;
    vp_playing=false;

    emit vp_file_opened();

    player->setVolume(20);



    //player->play();

}
void videoplayer::btnPlay_clicked(){

    vp_playcontrol();

}

void videoplayer::btnStop_clicked(){
    vp_stopcontrol();
}

void videoplayer::btnvol_clicked(){
    set_vpvol(vp_vol);
}
void videoplayer::vp_playcontrol(){
    if (vp_playing)
         player->pause();
    else {
        player->play();
    }


    vp_playing=!vp_playing;

}

void videoplayer::vp_stopcontrol(){

    player->stop();
    vp_playing=false;
    UI3280Player::playing=true;



}
void videoplayer::set_vpvol(int value){

 player->setVolume(value);


}


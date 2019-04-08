#include "ui3280player.h"
#include "ui_ui3280player.h"
#include "iconhelper.h"
#include "flatui.h"
#include <QTime>
#pragma comment( lib, "Winmm.lib" )
#pragma execution_character_set("utf-8")
static bool max=false;
bool UI3280Player::playing=false;
static bool mute=false;
QString UI3280Player::a="";
static bool videoplayer_opened=false;
int UI3280Player::d3=0;
int UI3280Player::index=0;
QStringList UI3280Player::songnamelist;
QStringList UI3280Player::singerlist;
QStringList  UI3280Player::albumlist;
QStringList  UI3280Player::pathlist;
UI3280Player::UI3280Player(QWidget *parent) : QDialog(parent), ui(new Ui::UI3280Player)
{

    ui->setupUi(this);
    this->initForm();
    this->initStyle();
    this->initList();
    this->search_bar();
    kernel = new WavePlayer(this);
    connect(kernel,SIGNAL(doneWork()),this,SLOT(on_doneWork()));

    connect(this,SIGNAL(btnPlay_clicked()),kernel,SLOT(onplayclicked()));
    connect(this,SIGNAL( btnvol_clicked()),kernel,SLOT(on_vol_move()));

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ProvideContextMenu(const QPoint &)));
    myTimer = new QTimer(this);


    connect(myTimer,SIGNAL(timeout()),this,SLOT(showTime()));


}


UI3280Player::~UI3280Player()
{
    delete ui;
}

bool UI3280Player::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->widgetTitle && event->type() == QEvent::MouseButtonDblClick) {
        if (!max)
            showMaximized();
        else showNormal();
        max=!max;
        return true;
    }

    return QWidget::eventFilter(watched, event);
}

void UI3280Player::initForm()
{
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf001), 20);
    IconHelper::Instance()->setIcon(ui->btn_Min, QChar(0xf068), 12);
    IconHelper::Instance()->setIcon(ui->btn_Max, QChar(0xf067), 12);
    IconHelper::Instance()->setIcon(ui->btn_Close, QChar(0xf00d), 12);
    IconHelper::Instance()->setIcon(ui->volumeBtn, QChar(0xf028), 13);
    IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04b), 13);
    IconHelper::Instance()->setIcon(ui->btnStop, QChar(0xf04d), 13);
    IconHelper::Instance()->setIcon(ui->btnPre, QChar(0xf048), 12);
    IconHelper::Instance()->setIcon(ui->btnNext, QChar(0xf051), 12);
    IconHelper::Instance()->setIcon(ui->btnSearch, QChar(0xf002), 12);
    IconHelper::Instance()->setIcon(ui->btn_Video, QChar(0xf03d), 12);

    ui->labTitle->setText("CSCI 3280 Player");
    this->setWindowTitle(ui->labTitle->text());
    ui->widgetTitle->installEventFilter(this);
    ui->widgetBottom->setProperty("flag","btnPlay");
    ui->slider->setMaximum(100);
}

void UI3280Player::initStyle()
{
    QStringList qss;

    //Font color
    qss.append(QString("*{outline:0px;color:#33CC66;}"));
    qss.append(QString("QLabel#labTitle{font:%2pt;}").arg(14));

    //Top barr
    qss.append("QWidget#widgetTitle{background:qlineargradient"
               "(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 #0973AB,stop:1 #339900);}"
               "QToolButton::menu-indicator{image:None;}");

    //3 btn on menu bar
    qss.append("QWidget#widgetMenu QAbstractButton{"
               "border:0px solid #0066CC;}");
    qss.append("QWidget#widgetMenu QAbstractButton:hover,"
               "QWidget#widgetMenu QAbstractButton:pressed{"
               "background:#067DB8;}");

    //Left song list
    qss.append(QString("QListView{padding:5px;background-color:rgba(29,34,40,100);font:%1pt;}").arg(12));
    qss.append("QListView::item:hover{background:#617D90;}");
    qss.append("QListView::item:selected{background:rgba(0,187,226,150);}");


    //Border color and width
    qss.append("QListView,QWidget#widgetBottom,QWidget#widgetWave,QWidget#WidgetInfoBox{border-style:solid;border-color:#505050;}");
    qss.append("QListView{border-width:1px 1px 0px 1px;}");
    qss.append("QWidget#widgetBottom{border-width:1px 1px 1px 1px;}");
    qss.append("QWidget#widgetWave{border-width:1px 1px 0px 0px;}");
    qss.append("QWidget#WidgetInfoBox{border-width:1px 1px 1px 1px;}");

    //Main BG Color
    qss.append("QWidget#widgetMain{background-color:rgba(29,34,40,220);}");

    //btn effect
    qss.append("QWidget[flag=\"btnPlay\"] QAbstractButton{background:#00CC66;color:#F0F0F0;}");
    qss.append("QWidget[flag=\"btnPlay\"] QAbstractButton:hover{background:#009933;}");
    qss.append("#btnPlay{border-radius:17px;}");
    qss.append("#btnStop{border-radius:17px;}");
    qss.append("#btnPre,#btnNext{border-radius:15px;}");


    FlatUI::Instance()->setSliderQss(ui->slider, 8, "rgba(29,34,56,150)", "rgba(37,156,210,150)", "rgba(250,250,250,100)");
    FlatUI::Instance()->setSliderQss(ui->volumeSlider, 8, "rgba(29,34,56,150)", "rgba(37,156,210,150)", "rgba(250,250,250,100)");
    ui->lyrics_display->setStyleSheet("QTextBrowser{background-color:rgba(29,34,40,100)}");
    qApp->setStyleSheet(qss.join(""));
}

void UI3280Player::initList()
{
//place to add data
    QString song = "Hello", singer="Adele";
    ui->listWidget->addItem(singer+" - "+ song);
    ui->listWidget->addItem("daan2");



}

void UI3280Player::showTime(){
    if (kernel->getPlayerState()!=0){
    cnt++;
    qDebug()<<cnt;


    lyrics_display();
    sliderwork();
    }
}

void UI3280Player::lyrics_display(){


    qDebug()<<time_value[lyrics_index]<<cnt-1;
    if (cnt-1==time_value[lyrics_index]){
        for(int a=0;a<lyrics_index;a++){
            QTextCursor cursor(ui->lyrics_display->document()->findBlockByLineNumber(a));
            QTextBlockFormat TBF = cursor.blockFormat();
            TBF.setBackground(QBrush(Qt::transparent));
            cursor.setBlockFormat(TBF);
        }

        QTextCursor cursor1(ui->lyrics_display->document()->findBlockByLineNumber(lyrics_index));
        QTextBlockFormat TBF1 = cursor1.blockFormat();
        TBF1.setBackground(QBrush(Qt::yellow));
        cursor1.setBlockFormat(TBF1);
        ui->lyrics_display->setTextCursor(cursor1);
        lyrics_index++;
    }
}
void UI3280Player::on_btn_Min_clicked()
{
    showMinimized();
}

void UI3280Player::on_btn_Max_clicked()
{
    if (!max)
        showMaximized();
    else showNormal();
    max=!max;
}

void UI3280Player::on_btn_Close_clicked()
{
    emit btnPlay_clicked();
    close();
}
void UI3280Player::search_bar()
{
    pathlist.clear();
    songnamelist.clear();
    singerlist.clear();
    albumlist.clear();

    ui->listWidget->clear();
    QString searchtext = ui->lineEdit->text();
    QStringList searchlist;
    if(searchtext.indexOf(" ",0)!=-1){
      searchlist = searchtext.split(' ', QString::SkipEmptyParts);
    }
    else{
        searchlist.append(searchtext);
    }
    QStringList txtfile;
    QString fullpath = "music_database.txt";
    QFile file(fullpath);
    if (!file.exists()) {
        qDebug()<<"database not found.";
        return;
    }
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!file.atEnd()){
        txtfile.append(file.readLine());
    }
    QList<int> flaglist;
    for (int i=0;i<txtfile.size();i++){
        flaglist.append(0);
        for(int x=0;x<searchlist.size();x++){
            if(txtfile[i].indexOf(searchlist[x],0,Qt::CaseInsensitive)!=-1){
                flaglist[i]=1;

            }
        }
    }

    for(int q=0; q<flaglist.size();q++){
        pathlist.append(txtfile[q].split(",").at(0));
        songnamelist.append(txtfile[q].split(",").at(1));
        singerlist.append(txtfile[q].split(",").at(2));
        albumlist.append(txtfile[q].split(",").at(3));

    }
    int added=0;
    for (int i=0;i<Client_Form::textfile.length();i++){
        qDebug()<<"running";
         qDebug()<<Client_Form::textfile[i].split(",").at(1);
        if (songnamelist.contains(Client_Form::textfile[i].split(",").at(1))){
            qDebug()<<"duplicated";

        }else {
            qDebug()<<"else";
            pathlist.append(Client_Form::textfile[i].split(",").at(0));
            songnamelist.append(Client_Form::textfile[i].split(",").at(1));
            singerlist.append(Client_Form::textfile[i].split(",").at(2));
            albumlist.append(Client_Form::textfile[i].split(",").at(3));
            added++;

            flaglist.append(0);
            for(int x=0;x<searchlist.size();x++)
                if(Client_Form::textfile[i].indexOf(searchlist[x],0,Qt::CaseInsensitive)!=-1)
                    flaglist.last()=1;

        }
        qDebug()<<"quit";
    }

    for(int w=0;w<flaglist.size();w++){
        if(flaglist[w]==1){
             ui->listWidget->addItem(songnamelist[w]);
       }
    }

}
void UI3280Player::on_btnSearch_clicked()
{
    search_bar();

}


void UI3280Player::on_btnStop_clicked()
{
    IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04b), 13);
    ui->slider->setValue(0);
    ui->Singer->setText("");
    ui->Song->setText("");
    ui->Album->setText("");
    ui->lyrics_display->clear();
    myTimer->stop();
    cnt=0;

    ui->labTimePlay->setText("00:00");
    ui->labTimeAll->setText("00:00");
    kernel->stopPlaying();

    emit btnStop_clicked();


}

void UI3280Player::on_btnPlay_clicked()
{
  if (videoplayer_opened){
   if (UI3280Player::playing)
        IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04c), 13);
   else
       IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04b), 13);

   UI3280Player::playing=!UI3280Player::playing;
   emit btnPlay_clicked();
    }
    else {

        if (kernel->getPlayerState()==0&&videoplayer_opened==false){
            IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04c), 13);
             kernel->playMusic(tempName);
             ui->Song->setText(songnamelist[index]);
              ui->Singer->setText(singerlist[index]);
               ui->Album->setText(albumlist[index]);
             qDebug()<<193;
        }
        else if (kernel->getPlayerState()==1&&videoplayer_opened==false)
        {
            IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04b), 13);
            qDebug()<<197;
            myTimer->stop();
             emit btnPlay_clicked();
        }
        else if (kernel->getPlayerState()==2&&videoplayer_opened==false)
             {
            IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04c), 13);
            qDebug()<<200;
            myTimer->start();
             emit btnPlay_clicked();
        }
    }


}

void UI3280Player::on_btnNext_clicked()
{

}



void UI3280Player::on_btnPre_clicked()
{

}

void UI3280Player::on_volumeBtn_clicked()
{
    if (!mute)
    {
        ui->volumeSlider->setValue(0);
        ui->volumeSlider->value();
        videoplayer::vp_vol=0;
        IconHelper::Instance()->setIcon(ui->volumeBtn, QChar(0xf026), 13);
    }
    else {IconHelper::Instance()->setIcon(ui->volumeBtn, QChar(0xf028), 13);
    ui->volumeSlider->setValue(99);
    videoplayer::vp_vol=99;
    }

    mute=!mute;
    emit btnvol_clicked();

}


void UI3280Player::lyrics_handler(QString path){
	ui->lyrics_display->clear();
    QStringList txtfile;
    QString fullpath = path+".lrc";
    QFile file(fullpath);
    if (!file.exists()) {
        qDebug()<<"lyrics not found.";
        return;
    }

    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!file.atEnd()){
        txtfile.append(file.readLine());
    }
    QStringList time;
    QStringList lyrics;
    lyrics.clear();
    for (int i=0;i<txtfile.length();i++){
        time.append(txtfile[i].split("]").at(0));
        lyrics.append(txtfile[i].split("]").at(1));

    }
	
    for (int a=0;a<time.length();a++){
        QString str1 =time[a].mid(1,5);
        qDebug()<<"test"<<str1;
        QTime time = QTime::fromString(str1, "mm:ss");
        time_value[a]=QTime(0,0).secsTo(time);

    }
    for(int a=0;a<lyrics.length();a++){
        QTextCursor cursor(ui->lyrics_display->document()->findBlockByLineNumber(a));
        QTextBlockFormat TBF = cursor.blockFormat();
        cursor.select(QTextCursor::WordUnderCursor);
        cursor.insertText(lyrics[a]);
        TBF.setBackground(QBrush(Qt::transparent));
        cursor.setBlockFormat(TBF);
    }

}


void UI3280Player::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{


    lyrics_index=0;

    IconHelper::Instance()->setIcon(ui->btnPlay, QChar(0xf04c), 13);
    playing=true;
    sliderwork();
    ui->Song->setText(item->text());
    QString song=item->text();
    for (int i=0;i<songnamelist.length();i++){
        if (songnamelist[i]==song){
            ui->Singer->setText(singerlist[i]);
            ui->Album->setText(albumlist[i]);
            index=i;
            break;
        }
    }

    songName=(const char *)pathlist[index].toLocal8Bit();


    qDebug()<<kernel->getPlayerState();
    tempName="music/"+songName;
    std::cout<<tempName<<std::endl;

    lyrics_handler(songnamelist[index]);
    songName=tempName;

    std::string dedmo="music/numb.wav";
    if (kernel->getPlayerState()==1||kernel->getPlayerState()==2){

        kernel->stopPlaying();
        myTimer->stop();
    }
    else {
        kernel->playMusic(songName);
        myTimer->start(1000);
        cnt=0;
        songName.clear();

    };



}

void UI3280Player::on_doneWork(){

    qDebug()<<"whatthefuck";
     qDebug()<<kernel->getPlayerState();
    kernel->playMusic(songName);
    qDebug()<<"whatthefuck";
    cnt=0;
    if (kernel->getPlayerState()!=0){
        myTimer->start();
        sliderwork();
        songName.clear();
    }
}
void UI3280Player::on_btn_Video_clicked()
{
    videoplayer_opened=true;
    videoplayer1= new videoplayer(this);
    videoplayer1->show();

    connect(videoplayer1,SIGNAL(vp_file_opened()),this,SLOT(vp_file_opened2()));
    connect(this,SIGNAL(btnPlay_clicked()),videoplayer1,SLOT(btnPlay_clicked()));
    connect(this,SIGNAL(btnStop_clicked()),videoplayer1,SLOT(btnStop_clicked()));
    connect(this,SIGNAL(btnvol_clicked()),videoplayer1,SLOT(btnvol_clicked()));
    connect(videoplayer1,SIGNAL(sliderwork()),this,SLOT(sliderwork()));
    connect(videoplayer1,SIGNAL(vi_stop()),this,SLOT(vi_stop()));
    connect(this,SIGNAL(slider_changed()),videoplayer1,SLOT(slider_changed()));


}

void UI3280Player::test(int value){

    qDebug()<<value;
}
void UI3280Player::sliderwork(){
    if (videoplayer_opened) {
        ui->labTimePlay->setText(videoplayer::nowTime);
        ui->labTimeAll->setText(videoplayer::totalTime);
        ui->slider->setValue(videoplayer::vp_current);
    }
    else {
        QString nowle=QString("%1").arg(cnt/60,2,10, QChar('0'))+":"+QString("%1").arg(cnt%60,2,10,QChar('0'));
        ui->labTimePlay->setText(nowle);
        ui->labTimeAll->setText(WavePlayer::totalle);
       test_ff=WavePlayer::duration;
        int idk=test_ff+1;
        idk+=0;

       ui->slider->setValue(cnt*100/idk);

    }


}

void UI3280Player::vi_stop(){
on_btnStop_clicked();
}

void UI3280Player::ProvideContextMenu(const QPoint &pos)
{
    QPoint item = ui->listWidget->mapToGlobal(pos);
    QMenu submenu;
    submenu.addAction("Edit");
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(item);
    if (rightClickItem && rightClickItem->text().contains("Delete") )
    {
        ui->listWidget->takeItem(ui->listWidget->indexAt(pos).row());

    }

    if (rightClickItem && rightClickItem->text().contains("Edit") )
    {
            if (ui->listWidget->indexAt(pos).row()!=-1)

            {
                UI3280Player::a=ui->listWidget->item(ui->listWidget->indexAt(pos).row())->text();
                index=ui->listWidget->indexAt(pos).row();
                editform= new Edit_Form(this);
                editform->show();

            }

    }
}

void UI3280Player::vp_file_opened2()
{

    on_btnPlay_clicked();


}

void UI3280Player::on_volumeSlider_valueChanged(int value)
{
    if (value==0)
        IconHelper::Instance()->setIcon(ui->volumeBtn, QChar(0xf026), 13);
        else IconHelper::Instance()->setIcon(ui->volumeBtn, QChar(0xf028), 13);
     if (videoplayer_opened){
        videoplayer::vp_vol=value;
     }

      d3=value;
     //std::cout<<d3<<std::endl;
    emit btnvol_clicked();
}





void UI3280Player::on_slider_sliderReleased()
{
    videoplayer::vp_userslided=ui->slider->value();
    videoplayer::vp_userslided=videoplayer::vp_userslided*videoplayer::vp_durationval/100;
    emit slider_changed();
}


void UI3280Player::load_outside_db(){
       this->search_bar();
}

void UI3280Player::on_server_btn_clicked()
{
   serverform= new Server_Form(this);
    serverform->show();
}

void UI3280Player::on_client_btn_clicked()
{
    clientform= new Client_Form(this);
    clientform->show();
    connect(clientform,SIGNAL(loaded()),this,SLOT(load_outside_db()));
}

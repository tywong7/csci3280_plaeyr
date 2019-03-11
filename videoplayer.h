#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>


namespace Ui {
class videoplayer;
}

class videoplayer : public QDialog
{
    Q_OBJECT

public:
    explicit videoplayer(QWidget *parent = nullptr);
    ~videoplayer();
    bool static vp_playing;
    int static vp_vol;
    qint64 static vp_duration;
    qint64 static vp_current;
    QString static totalTime;
    QString static nowTime;
    qint64 static vp_userslided;
    qint64 static vp_durationval;
protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void initForm();

    void on_btn_close_clicked();
    void on_btn_file_clicked();
    void vp_playcontrol();
    void btnPlay_clicked();
    void vp_stopcontrol();
    void btnStop_clicked();
    void set_vpvol(int value);
    void btnvol_clicked();
    void checkPosition(qint64 x);
    void getDuration(qint64 x);
    void slider_changed();
signals: void vp_file_opened();
         void sliderwork();
         void vi_stop();
private:
    Ui::videoplayer *ui;
    QMediaPlayer* player= new QMediaPlayer;
    QVideoWidget *wid = new QVideoWidget;



};

#endif // VIDEOPLAYER_H

﻿#ifndef UI3280PLAYER_H
#define UI3280PLAYER_H

#include <QDialog>
#include<QListWidget>
#include "edit_form.h"
#include "videoplayer.h"
#include <QSlider>
#include <QtCore>
#include <QStringList>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include "playWave.hpp"

namespace Ui {
class UI3280Player;
}

class UI3280Player : public QDialog
{
    Q_OBJECT
public:
    static QString a;
    static bool playing;


public:
    explicit UI3280Player(QWidget *parent = nullptr);
    ~UI3280Player();


protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void lyrics_display();

private:
    Ui::UI3280Player *ui;
    Edit_Form *editform;
    videoplayer *videoplayer1;
    QTimer *myTimer;
    int cnt=0,test_ff=0;
public:
    WavePlayer *kernel;
    std::string songName;
    std::string tempName;
    int static d3;

private slots:
    void initForm();
    void initStyle();
    void initList();
    void showTime();

private slots:

    void on_btn_Min_clicked();
    void on_btn_Max_clicked();
    void on_btn_Close_clicked();
    void on_btnSearch_clicked();
    void on_btnStop_clicked();
    void on_btnPlay_clicked();
    void on_btnNext_clicked();
    void on_btnPre_clicked();
    void on_volumeBtn_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_btn_Video_clicked();
    void vp_file_opened2();
    void ProvideContextMenu(const QPoint &);
    void test(int value);
    void sliderwork();
    void on_volumeSlider_valueChanged(int value);
    void vi_stop();
    void on_slider_sliderReleased();
    void on_doneWork();


signals:
    void btnPlay_clicked();
    void btnStop_clicked();
    void btnvol_clicked();
    void slider_changed();
};

#endif // UI3280PLAYER_H

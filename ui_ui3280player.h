/********************************************************************************
** Form generated from reading UI file 'ui3280player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI3280PLAYER_H
#define UI_UI3280PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI3280Player
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QPushButton *btn_Max;
    QPushButton *btn_Min;
    QPushButton *btn_Close;
    QPushButton *btn_Video;
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *searchBox;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *btnSearch;
    QWidget *WidgetInfoBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label1;
    QLabel *Singer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *song_tag;
    QLabel *Song;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Album_tag;
    QLabel *Album;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widgetLyrics;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *lyrics_display;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widgetBottom;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnPre;
    QPushButton *btnPlay;
    QPushButton *btnStop;
    QPushButton *btnNext;
    QHBoxLayout *horizontalLayout;
    QLabel *labTimePlay;
    QSlider *slider;
    QLabel *labTimeAll;
    QPushButton *volumeBtn;
    QSlider *volumeSlider;

    void setupUi(QDialog *UI3280Player)
    {
        if (UI3280Player->objectName().isEmpty())
            UI3280Player->setObjectName(QString::fromUtf8("UI3280Player"));
        UI3280Player->resize(824, 600);
        UI3280Player->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(UI3280Player);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(UI3280Player);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        widgetTitle->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy);
        labTitle->setStyleSheet(QString::fromUtf8(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_Max = new QPushButton(widgetMenu);
        btn_Max->setObjectName(QString::fromUtf8("btn_Max"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_Max->sizePolicy().hasHeightForWidth());
        btn_Max->setSizePolicy(sizePolicy1);
        btn_Max->setMinimumSize(QSize(40, 30));
        btn_Max->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(btn_Max, 0, 3, 1, 1);

        btn_Min = new QPushButton(widgetMenu);
        btn_Min->setObjectName(QString::fromUtf8("btn_Min"));
        sizePolicy1.setHeightForWidth(btn_Min->sizePolicy().hasHeightForWidth());
        btn_Min->setSizePolicy(sizePolicy1);
        btn_Min->setMinimumSize(QSize(40, 30));
        btn_Min->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(btn_Min, 0, 1, 1, 1);

        btn_Close = new QPushButton(widgetMenu);
        btn_Close->setObjectName(QString::fromUtf8("btn_Close"));
        sizePolicy1.setHeightForWidth(btn_Close->sizePolicy().hasHeightForWidth());
        btn_Close->setSizePolicy(sizePolicy1);
        btn_Close->setMinimumSize(QSize(40, 30));
        btn_Close->setCursor(QCursor(Qt::ArrowCursor));
        btn_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btn_Close, 0, 4, 1, 1);

        btn_Video = new QPushButton(widgetMenu);
        btn_Video->setObjectName(QString::fromUtf8("btn_Video"));
        sizePolicy1.setHeightForWidth(btn_Video->sizePolicy().hasHeightForWidth());
        btn_Video->setSizePolicy(sizePolicy1);
        btn_Video->setMinimumSize(QSize(40, 30));
        btn_Video->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(btn_Video, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        widgetMain = new QWidget(UI3280Player);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        widgetMain->setEnabled(true);
        verticalLayout_3 = new QVBoxLayout(widgetMain);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        searchBox = new QHBoxLayout();
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        label_4 = new QLabel(widgetMain);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(65, 30));
        label_4->setMaximumSize(QSize(60, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        searchBox->addWidget(label_4);

        lineEdit = new QLineEdit(widgetMain);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(false);
        lineEdit->setFont(font1);

        searchBox->addWidget(lineEdit);

        btnSearch = new QPushButton(widgetMain);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        sizePolicy2.setHeightForWidth(btnSearch->sizePolicy().hasHeightForWidth());
        btnSearch->setSizePolicy(sizePolicy2);
        btnSearch->setMinimumSize(QSize(40, 40));
        btnSearch->setMaximumSize(QSize(40, 40));

        searchBox->addWidget(btnSearch);


        verticalLayout_3->addLayout(searchBox);

        WidgetInfoBox = new QWidget(widgetMain);
        WidgetInfoBox->setObjectName(QString::fromUtf8("WidgetInfoBox"));
        WidgetInfoBox->setEnabled(true);
        verticalLayout_5 = new QVBoxLayout(WidgetInfoBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(WidgetInfoBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setMinimumSize(QSize(110, 40));
        label_3->setMaximumSize(QSize(100, 40));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_10->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label1 = new QLabel(WidgetInfoBox);
        label1->setObjectName(QString::fromUtf8("label1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label1->setFont(font2);

        horizontalLayout_7->addWidget(label1);

        Singer = new QLabel(WidgetInfoBox);
        Singer->setObjectName(QString::fromUtf8("Singer"));
        Singer->setMinimumSize(QSize(120, 0));
        Singer->setFont(font2);

        horizontalLayout_7->addWidget(Singer);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        song_tag = new QLabel(WidgetInfoBox);
        song_tag->setObjectName(QString::fromUtf8("song_tag"));
        song_tag->setMinimumSize(QSize(0, 0));
        song_tag->setMaximumSize(QSize(60, 16777215));
        song_tag->setFont(font2);

        horizontalLayout_6->addWidget(song_tag);

        Song = new QLabel(WidgetInfoBox);
        Song->setObjectName(QString::fromUtf8("Song"));
        Song->setMinimumSize(QSize(400, 0));

        horizontalLayout_6->addWidget(Song);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Album_tag = new QLabel(WidgetInfoBox);
        Album_tag->setObjectName(QString::fromUtf8("Album_tag"));
        Album_tag->setFont(font2);

        horizontalLayout_5->addWidget(Album_tag);

        Album = new QLabel(WidgetInfoBox);
        Album->setObjectName(QString::fromUtf8("Album"));

        horizontalLayout_5->addWidget(Album);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout_3->addWidget(WidgetInfoBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        listWidget = new QListWidget(widgetMain);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(true);
        listWidget->setMinimumSize(QSize(200, 0));
        listWidget->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_9->addWidget(listWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        widgetLyrics = new QWidget(widgetMain);
        widgetLyrics->setObjectName(QString::fromUtf8("widgetLyrics"));
        verticalLayout_7 = new QVBoxLayout(widgetLyrics);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        horizontalLayout_9->addWidget(widgetLyrics);

        lyrics_display = new QTextBrowser(widgetMain);
        lyrics_display->setObjectName(QString::fromUtf8("lyrics_display"));
        lyrics_display->setMinimumSize(QSize(500, 0));
        lyrics_display->setMaximumSize(QSize(400, 16777215));
        lyrics_display->setAcceptRichText(true);

        horizontalLayout_9->addWidget(lyrics_display);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        widgetBottom = new QWidget(widgetMain);
        widgetBottom->setObjectName(QString::fromUtf8("widgetBottom"));
        widgetBottom->setMinimumSize(QSize(0, 50));
        horizontalLayout_4 = new QHBoxLayout(widgetBottom);
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnPre = new QPushButton(widgetBottom);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setMinimumSize(QSize(30, 30));
        btnPre->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(btnPre);

        btnPlay = new QPushButton(widgetBottom);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setMinimumSize(QSize(35, 35));
        btnPlay->setMaximumSize(QSize(35, 35));

        horizontalLayout_3->addWidget(btnPlay);

        btnStop = new QPushButton(widgetBottom);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(35);
        sizePolicy5.setVerticalStretch(35);
        sizePolicy5.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy5);
        btnStop->setMinimumSize(QSize(35, 35));
        btnStop->setMaximumSize(QSize(35, 35));

        horizontalLayout_3->addWidget(btnStop);

        btnNext = new QPushButton(widgetBottom);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(30, 30));
        btnNext->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(btnNext);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labTimePlay = new QLabel(widgetBottom);
        labTimePlay->setObjectName(QString::fromUtf8("labTimePlay"));

        horizontalLayout->addWidget(labTimePlay);

        slider = new QSlider(widgetBottom);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider);

        labTimeAll = new QLabel(widgetBottom);
        labTimeAll->setObjectName(QString::fromUtf8("labTimeAll"));
        labTimeAll->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labTimeAll);

        volumeBtn = new QPushButton(widgetBottom);
        volumeBtn->setObjectName(QString::fromUtf8("volumeBtn"));
        volumeBtn->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(volumeBtn);

        volumeSlider = new QSlider(widgetBottom);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(100, 16777215));
        volumeSlider->setSliderPosition(99);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volumeSlider);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(widgetBottom);


        verticalLayout->addWidget(widgetMain);


        retranslateUi(UI3280Player);

        QMetaObject::connectSlotsByName(UI3280Player);
    } // setupUi

    void retranslateUi(QDialog *UI3280Player)
    {
        UI3280Player->setWindowTitle(QApplication::translate("UI3280Player", "Form", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
        btn_Max->setText(QString());
        btn_Min->setText(QString());
        btn_Close->setText(QString());
        btn_Video->setText(QString());
        label_4->setText(QApplication::translate("UI3280Player", "Search:", nullptr));
        btnSearch->setText(QString());
        label_3->setText(QApplication::translate("UI3280Player", "Now Playing:", nullptr));
        label1->setText(QApplication::translate("UI3280Player", "Singer:", nullptr));
        Singer->setText(QString());
        song_tag->setText(QApplication::translate("UI3280Player", "Song:", nullptr));
        Song->setText(QString());
        Album_tag->setText(QApplication::translate("UI3280Player", "Album:", nullptr));
        Album->setText(QString());
        lyrics_display->setHtml(QApplication::translate("UI3280Player", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'PMingLiU'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        btnPre->setText(QString());
        btnPlay->setText(QString());
        btnStop->setText(QString());
        btnNext->setText(QString());
        labTimePlay->setText(QApplication::translate("UI3280Player", "00:00", nullptr));
        labTimeAll->setText(QApplication::translate("UI3280Player", "00:00", nullptr));
        volumeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UI3280Player: public Ui_UI3280Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI3280PLAYER_H

/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoplayer
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *vp_top;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_file;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QVBoxLayout *container;

    void setupUi(QDialog *videoplayer)
    {
        if (videoplayer->objectName().isEmpty())
            videoplayer->setObjectName(QString::fromUtf8("videoplayer"));
        videoplayer->resize(740, 569);
        videoplayer->setAutoFillBackground(false);
        videoplayer->setStyleSheet(QString::fromUtf8("QDialog{background-color:rgb(20,50,80)}"));
        verticalLayout_2 = new QVBoxLayout(videoplayer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        splitter = new QSplitter(videoplayer);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        vp_top = new QWidget(splitter);
        vp_top->setObjectName(QString::fromUtf8("vp_top"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vp_top->sizePolicy().hasHeightForWidth());
        vp_top->setSizePolicy(sizePolicy1);
        vp_top->setMinimumSize(QSize(720, 0));
        horizontalLayout = new QHBoxLayout(vp_top);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_file = new QPushButton(vp_top);
        btn_file->setObjectName(QString::fromUtf8("btn_file"));
        btn_file->setMinimumSize(QSize(40, 40));
        btn_file->setMaximumSize(QSize(40, 40));
        btn_file->setStyleSheet(QString::fromUtf8("QPushButton{background:#143250;border:0px}\n"
"QPushButton:hover{background:#144950;};\n"
""));

        horizontalLayout->addWidget(btn_file);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(vp_top);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setMinimumSize(QSize(40, 40));
        btn_close->setMaximumSize(QSize(40, 40));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton{background:#143250;border:0px}\n"
"QPushButton:hover{background:#144950;};\n"
""));

        horizontalLayout->addWidget(btn_close);

        splitter->addWidget(vp_top);

        verticalLayout_2->addWidget(splitter);

        container = new QVBoxLayout();
        container->setObjectName(QString::fromUtf8("container"));

        verticalLayout_2->addLayout(container);


        retranslateUi(videoplayer);

        QMetaObject::connectSlotsByName(videoplayer);
    } // setupUi

    void retranslateUi(QDialog *videoplayer)
    {
        videoplayer->setWindowTitle(QApplication::translate("videoplayer", "Dialog", nullptr));
        btn_file->setText(QString());
        btn_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class videoplayer: public Ui_videoplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H

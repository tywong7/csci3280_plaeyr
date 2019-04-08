/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Edit_Form
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *edit_bg;
    QVBoxLayout *verticalLayout_2;
    QWidget *bar3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *port_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Edit_Form)
    {
        if (Edit_Form->objectName().isEmpty())
            Edit_Form->setObjectName(QString::fromUtf8("Edit_Form"));
        Edit_Form->resize(400, 300);
        Edit_Form->setWindowOpacity(0.700000000000000);
        Edit_Form->setStyleSheet(QString::fromUtf8("QDialog{background-color:rgba(29,34,40,90)}"));
        horizontalLayout_4 = new QHBoxLayout(Edit_Form);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        edit_bg = new QWidget(Edit_Form);
        edit_bg->setObjectName(QString::fromUtf8("edit_bg"));
        edit_bg->setStyleSheet(QString::fromUtf8("QWidget{background-color:rgba(29,34,40,90)}"));
        verticalLayout_2 = new QVBoxLayout(edit_bg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        bar3 = new QWidget(edit_bg);
        bar3->setObjectName(QString::fromUtf8("bar3"));
        bar3->setEnabled(true);
        verticalLayout = new QVBoxLayout(bar3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(bar3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(54, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(bar3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        port_input = new QLineEdit(bar3);
        port_input->setObjectName(QString::fromUtf8("port_input"));
        port_input->setFont(font);

        horizontalLayout_2->addWidget(port_input);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(bar3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(bar3);

        buttonBox = new QDialogButtonBox(edit_bg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setMaximumSize(QSize(300, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        buttonBox->setFont(font1);
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{background:#00CC66;color:#F0F0F0;}\n"
"QPushButton:hover{background:#009933;}\");\n"
""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        horizontalLayout_4->addWidget(edit_bg);


        retranslateUi(Edit_Form);

        QMetaObject::connectSlotsByName(Edit_Form);
    } // setupUi

    void retranslateUi(QDialog *Edit_Form)
    {
        Edit_Form->setWindowTitle(QApplication::translate("Edit_Form", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Edit_Form", "Port", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Edit_Form: public Ui_Edit_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H

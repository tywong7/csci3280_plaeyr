/********************************************************************************
** Form generated from reading UI file 'server_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_FORM_H
#define UI_SERVER_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server_Form
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *edit_bg;
    QVBoxLayout *verticalLayout_2;
    QWidget *bar3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *port_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *port_input_2;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QPushButton *disconnect_btn;

    void setupUi(QDialog *Server_Form)
    {
        if (Server_Form->objectName().isEmpty())
            Server_Form->setObjectName(QString::fromUtf8("Server_Form"));
        Server_Form->resize(400, 300);
        Server_Form->setWindowOpacity(0.700000000000000);
        Server_Form->setStyleSheet(QString::fromUtf8("QDialog{background-color:rgba(29,34,40,90)}"));
        horizontalLayout_4 = new QHBoxLayout(Server_Form);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        edit_bg = new QWidget(Server_Form);
        edit_bg->setObjectName(QString::fromUtf8("edit_bg"));
        edit_bg->setStyleSheet(QString::fromUtf8("QWidget{background-color:rgba(29,34,40,90)}"));
        verticalLayout_2 = new QVBoxLayout(edit_bg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        bar3 = new QWidget(edit_bg);
        bar3->setObjectName(QString::fromUtf8("bar3"));
        bar3->setEnabled(true);
        horizontalLayout = new QHBoxLayout(bar3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(bar3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
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

        port_input_2 = new QLineEdit(bar3);
        port_input_2->setObjectName(QString::fromUtf8("port_input_2"));
        port_input_2->setFont(font);

        horizontalLayout_3->addWidget(port_input_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addWidget(bar3);

        label = new QLabel(edit_bg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(label);

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

        disconnect_btn = new QPushButton(edit_bg);
        disconnect_btn->setObjectName(QString::fromUtf8("disconnect_btn"));
        disconnect_btn->setAutoDefault(true);
        disconnect_btn->setFlat(false);

        verticalLayout_2->addWidget(disconnect_btn);


        horizontalLayout_4->addWidget(edit_bg);


        retranslateUi(Server_Form);

        disconnect_btn->setDefault(false);


        QMetaObject::connectSlotsByName(Server_Form);
    } // setupUi

    void retranslateUi(QDialog *Server_Form)
    {
        Server_Form->setWindowTitle(QApplication::translate("Server_Form", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Server_Form", "Port", nullptr));
        label_3->setText(QApplication::translate("Server_Form", "Configuration doc  ", nullptr));
        label->setText(QApplication::translate("Server_Form", "Status:", nullptr));
        disconnect_btn->setText(QApplication::translate("Server_Form", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server_Form: public Ui_Server_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_FORM_H

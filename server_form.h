#ifndef SERVER_FORM_H
#define SERVER_FORM_H

#include <QDialog>
namespace Ui {
class Server_Form;
}

class Server_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Server_Form(QWidget *parent = nullptr);
    ~Server_Form();
private slots:
    void initForm();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

    void on_disconnect_btn_clicked();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:
   void fire();
   void dis_clicked();

private:
    Ui::Server_Form *ui;
};


#endif // SERVER_FORM_H

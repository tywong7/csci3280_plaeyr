#ifndef CLIENT_FORM_H
#define CLIENT_FORM_H

#include <QDialog>
namespace Ui {
class Client_Form;
}

class Client_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Client_Form(QWidget *parent = nullptr);
    ~Client_Form();
    static QStringList  textfile;
private slots:
    void initForm();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Client_Form *ui;
signals:
    void loaded();
};


#endif // CLIENT_FORM_H

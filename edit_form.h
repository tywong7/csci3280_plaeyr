#ifndef EDIT_FORM_H
#define EDIT_FORM_H
#include <QDialog>
namespace Ui {
class Edit_Form;
}

class Edit_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Form(QWidget *parent = nullptr);
    ~Edit_Form();
private slots:
    void initForm();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Edit_Form *ui;
};
#endif // EDIT_FORM_H

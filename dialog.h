#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void loginBtnClicked();
    void exitBtnClicked();
    void on_check_clicked();
private:
   QLineEdit* userEdit;
   QLineEdit* passwordEdit;
   QWidget *mparent;
   QCheckBox* check;
};
#endif // DIALOG_H

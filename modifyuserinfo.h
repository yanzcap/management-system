#ifndef MODIFYUSERINFO_H
#define MODIFYUSERINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include "mainwindow.h"
class myMainWindow;
class modifyUserInfo : public QWidget
{
    Q_OBJECT
public:
    explicit modifyUserInfo(QWidget *parent = nullptr);

public slots:
    void saveBtnClicked();
    void on_check_clicked();
signals:
private:
    myMainWindow* _mainWindow;
    QLineEdit* userEdit;
    QLineEdit* passwordEdit;
    QCheckBox* check;
};

#endif // MODIFYUSERINFO_H

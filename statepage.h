#ifndef STATEPAGE_H
#define STATEPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

#include "mainwindow.h"
class myMainWindow;

class statePage : public QWidget
{
    Q_OBJECT
public:
    explicit statePage(QWidget *parent = nullptr);
public slots:
    void tabCurrentChanged(int index);
    void currentIndexChanged(int index);
signals:
private slots:
    void stateBtnClicked();
private:
    myMainWindow* _mainWindow;
    QLineEdit* noEdit;
    QLineEdit* nameEdit;
    QLineEdit* sexEdit;
    QLineEdit* ageEdit;
    QLineEdit* majorEdit;
    QLineEdit* temEdit;
    QComboBox *comBox;
    QComboBox *comBox1;
    QComboBox *comBox2;
    QComboBox *comBox3;
    void comboAddData();

};

#endif // STATEPAGE_H

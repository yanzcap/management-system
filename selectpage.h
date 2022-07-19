#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "mainwindow.h"
class myMainWindow;
class selectPage : public QWidget
{
    Q_OBJECT
public:
    explicit selectPage(QWidget *parent = nullptr);
public slots:
    void tabCurrentChanged(int index);
signals:
private slots:
    void searchBtnClicked();    
private:
    myMainWindow* _mainWindow;
    QLineEdit* noEdit;
    QLineEdit* nameEdit;
    QLineEdit* sexEdit;
    QLineEdit* ageEdit;
    QLineEdit* majorEdit;
    QLineEdit* temEdit;
    QComboBox *comBox;
    void comboAddData();

};

#endif // SELECTPAGE_H

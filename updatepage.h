#ifndef UPDATEPAGE_H
#define UPDATEPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "mainwindow.h"
class myMainWindow;

class updatePage : public QWidget
{
    Q_OBJECT
public:
    explicit updatePage(QWidget *parent = nullptr);
public slots:
    void tabCurrentChanged(int index);
    void currentIndexChanged(int index);
signals:    
private slots:
    void updateBtnClicked();
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

#endif // UPDATEPAGE_H

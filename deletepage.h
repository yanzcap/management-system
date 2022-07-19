#ifndef DELETEPAGE_H
#define DELETEPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "mainwindow.h"
class myMainWindow;

class deletePage : public QWidget
{
    Q_OBJECT
public:
    explicit deletePage(QWidget *parent = nullptr);
public slots:
    void tabCurrentChanged(int index);
    void currentIndexChanged(int index);
signals:
private slots:   
    void deleteBtnClicked();
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

#endif // DELETEPAGE_H

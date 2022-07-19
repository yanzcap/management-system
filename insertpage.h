#ifndef INSERTPAGE_H
#define INSERTPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "mainwindow.h"
class myMainWindow;

class insertPage : public QWidget
{
    Q_OBJECT
public:
    explicit insertPage(QWidget *parent = nullptr);

signals:
private slots:
    void insertBtnClicked();
    void resetBtnClicked();
private:
    myMainWindow* _mainWindow;
    QLineEdit* noEdit;
    QLineEdit* nameEdit;
    QLineEdit* sexEdit;
    QLineEdit* ageEdit;
    QLineEdit* majorEdit;
    QLineEdit* temEdit;
};

#endif // INSERTPAGE_H

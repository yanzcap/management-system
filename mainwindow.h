#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QTabWidget>
#include "selectpage.h"
#include "insertpage.h"
#include "updatepage.h"
#include "deletepage.h"
#include "modifyuserinfo.h"
#include "contactdata.h"
#include "statepage.h"

class selectPage;
class insertPage;
class updatePage;
class deletePage;
class modifyUserInfo;
class statePage;
class myMainWindow : public QDialog
{
    Q_OBJECT
    QTabWidget *tabWidget;
public:
    explicit myMainWindow(QWidget *parent = nullptr);
    QList<contactData> getcontactList();
    contactData getcontactInfoByName(QString name1); //查询
    bool insertcontactInfo(contactData sd1);  //添加或新增： no唯一
    bool deletecontactInfo(QString no1);

signals:

private:
    selectPage* selectPageWidget;
    insertPage* insertPageWidget;
    updatePage* updatePageWidget;
    deletePage* deletePageWidget;
    modifyUserInfo* modifyUserInfoWidget;
    statePage* statePageWidget;
    QList<contactData> _contactDataList;

};

#endif // MAINWINDOW_H

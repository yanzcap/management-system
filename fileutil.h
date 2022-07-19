#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QObject>
#include <QWidget>
#include "contactdata.h"
#include <QList>
#include "userinfodata.h"

class fileUtil : public QObject
{
    Q_OBJECT
public:
    explicit fileUtil(QObject *parent = nullptr);
    QString readFile(QString fileName);
    bool writeFile(QString fileName,QString text);
    QList<contactData> readcontactData();
    bool  writecontactData(QList<contactData> contactList);
    QList<userInfoData> readUserinfoData();
    bool writeUserinfoData(QList<userInfoData> userList);

signals:

};

#endif // FILEUTIL_H

#ifndef USERINFODATA_H
#define USERINFODATA_H
#include <QString>
#include <QStringList>

class userInfoData
{
public:
    userInfoData();
    userInfoData(QStringList usrInfoTmp);

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private:
    QString username;
    QString password;
};

#endif // USERINFODATA_H

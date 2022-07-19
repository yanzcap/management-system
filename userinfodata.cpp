#include "userinfodata.h"

userInfoData::userInfoData()
{

}

userInfoData::userInfoData(QStringList usrInfoTmp)
{
    if(!usrInfoTmp.isEmpty() && usrInfoTmp.length()==2){
       setUsername(usrInfoTmp[0]);
       setPassword(usrInfoTmp[1]);
    }
}

QString userInfoData::getUsername() const
{
    return username;
}

void userInfoData::setUsername(const QString &value)
{
    username = value;
}

QString userInfoData::getPassword() const
{
    return password;
}

void userInfoData::setPassword(const QString &value)
{
    password = value;
}

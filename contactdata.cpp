#include "contactdata.h"
#include <QString>
using namespace std;

contactData::contactData()
{

}

contactData::contactData(QStringList contactTmp)
{
    if(!contactTmp.isEmpty() && contactTmp.length()==6){
       setcontact_no(contactTmp[0]);
       setcontact_name(contactTmp[1]);
       setcontact_sex(contactTmp[2]);
       setcontact_age(contactTmp[3]);
       setcontact_major(contactTmp[4]);
       setcontact_tem(contactTmp[5]);
    }
}

QString contactData::getcontact_no() const
{
    return contact_no;
}

void contactData::setcontact_no(QString value)
{
    contact_no = QString(value);
}

QString contactData::getcontact_name() const
{
    return contact_name;
}

void contactData::setcontact_name(QString value)
{
    contact_name = QString(value);
}

QString contactData::getcontact_sex() const
{
    return contact_sex;
}

void contactData::setcontact_sex(QString value)
{
    contact_sex = QString(value);
}

QString contactData::getcontact_age() const
{
    return contact_age;
}

void contactData::setcontact_age(QString value)
{
    contact_age = QString(value);
}

QString contactData::getcontact_major() const
{
    return contact_major;
}

void contactData::setcontact_major(QString value)
{
    contact_major = QString(value);
}

QString contactData::getcontact_tem() const
{
    return contact_tem;
}

void contactData::setcontact_tem(QString value)
{
    contact_tem = QString(value);
}

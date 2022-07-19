#ifndef STUDENTDATA_H
#define STUDENTDATA_H
#include <QString>
#include <QStringList>

class contactData
{
public:
    contactData();
    contactData(QStringList contactTmp);
    QString getcontact_no() const;
    void setcontact_no(QString value);

    QString getcontact_name() const;
    void setcontact_name(QString value);

    QString getcontact_sex() const;
    void setcontact_sex(QString value);

    QString getcontact_age() const;
    void setcontact_age(QString value);

    QString getcontact_major() const;
    void setcontact_major(QString value);

    QString getcontact_tem() const;
    void setcontact_tem(QString value);

private:
    QString contact_no;
    QString contact_name;
    QString contact_sex;
    QString contact_age;
    QString contact_major;
    QString contact_tem;
};

#endif // STUDENTDATA_H

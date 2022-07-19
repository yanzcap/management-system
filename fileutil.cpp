#include "fileutil.h"
#include <QDebug>
#include <QFile>

const QString contactInfoFileName="E:/contactMIS/res/contactdata.txt";
const QString userInfoFileName="E:/contactMIS/res/userinfo.txt";

fileUtil::fileUtil(QObject *parent) : QObject(parent)
{

}

QString fileUtil::readFile(QString fileName)
{
    QString res="";
    if(fileName.isEmpty())
    {
        qDebug()<<"Empty File";
        return NULL;
    }

    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        in.setCodec("UTF-8");
        res=in.readAll();
        qDebug()<<res;
        file->close();
        //delete file;
    }
    else
    {
        qDebug()<<"Read File error!";
        return NULL;
    }
    return res;
}
bool fileUtil::writeFile(QString fileName, QString text)
{
    if(fileName.isEmpty() || text.isEmpty())
    {
        qDebug()<<"Empty File or text";
        return false;
    }
    QFile *file = new QFile;
    file->setFileName(fileName);
    if(file->isOpen())file->close();
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out.setCodec("UTF-8");
        out<<text;
        file->close();
       // delete file;
    }
    else
    {
        qDebug()<<"Save File Error!";
        return false;
    }
    return true;
}

QList<contactData> fileUtil::readcontactData()
{
  QString str0=readFile(contactInfoFileName);
  QList<contactData>* reslist=new QList<contactData>();
  if(!str0.isEmpty())
  {
     QStringList strList0=str0.split("\r\n",QString::SkipEmptyParts);
     if(!strList0.isEmpty() && strList0.length()>0)
     {
         for(int js=0;js<strList0.length();js++){
             QStringList strList1=strList0[js].split(",",QString::SkipEmptyParts);
             if(!strList1.isEmpty() && strList1.length()==6){
                contactData* stu1=new contactData(strList1);
                reslist->append(*stu1);
             }
         }
     }
  }
  return  *reslist;
}

bool fileUtil::writecontactData(QList<contactData> contactList)
{
   if(!contactList.isEmpty() && contactList.count()>0)
   {
       QString str="";
      for(int js=0;js<contactList.count();js++)
      {
         contactData sd1=contactList[js];
         str+=sd1.getcontact_no()+","+sd1.getcontact_name()+","+sd1.getcontact_sex()
                 +","+sd1.getcontact_age()+","+sd1.getcontact_major()+","+sd1.getcontact_tem()+"\r\n";
      }
      if(str.length()>0)
          writeFile(contactInfoFileName,str);
   }
}

QList<userInfoData> fileUtil::readUserinfoData()
{
    QString str0=readFile(userInfoFileName);
    QList<userInfoData>* reslist=new QList<userInfoData>();
    if(!str0.isEmpty())
    {
       QStringList strList0=str0.split("\r\n",QString::SkipEmptyParts);
       if(!strList0.isEmpty() && strList0.length()>0)
       {
           for(int js=0;js<strList0.length();js++){
               QStringList strList1=strList0[js].split(",",QString::SkipEmptyParts);
               if(!strList1.isEmpty() && strList1.length()==2){
                  userInfoData* user1=new userInfoData(strList1);
                  reslist->append(*user1);
               }
           }
       }
    }
    return  *reslist;
}

bool fileUtil::writeUserinfoData(QList<userInfoData> userList)
{
    if(!userList.isEmpty() && userList.count()>0)
    {
        QString str="";
       for(int js=0;js<userList.count();js++)
       {
          userInfoData user1=userList[js];
          str+=user1.getUsername()+","+user1.getPassword()+"\r\n";
       }
       if(str.length()>0)
           writeFile(userInfoFileName,str);
    }
}

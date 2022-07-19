#include "mainwindow.h"
#include "QVBoxLayout"
#include "fileutil.h"
#include <QLabel>

myMainWindow::myMainWindow(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout* vlay=new QVBoxLayout(this);
    tabWidget = new QTabWidget(this);
    //新建第一个页面的部件
    selectPageWidget=new selectPage(this);
    tabWidget->addTab(selectPageWidget, "查询信息");
    //新建第二个页面的部件
    insertPageWidget=new insertPage(this);
    tabWidget->addTab(insertPageWidget, "新增信息");
    //新建第三个页面的部件
    updatePageWidget=new updatePage(this);
    tabWidget->addTab(updatePageWidget, "修改信息");
    //新建第四个页面的部件
    deletePageWidget=new deletePage(this);
    tabWidget->addTab(deletePageWidget, "删除信息");
    //新建第五个页面的部件
    modifyUserInfoWidget=new modifyUserInfo(this);
    tabWidget->addTab(modifyUserInfoWidget, "用户信息");
    //新建第六个页面的部件
    statePageWidget=new statePage(this);
    tabWidget->addTab(statePageWidget, "防疫信息存储");
    vlay->addWidget(tabWidget);
    //插入图片
    QLabel *pTag = new QLabel(this);
    QImage image("E:/contactMIS/picture/virus.jpeg");
    pTag->setPixmap(QPixmap::fromImage(image));
    pTag->setGeometry(0,0,image.width(),image.height());
    vlay->addWidget(pTag);
    this->setLayout(vlay);

    connect(tabWidget,&QTabWidget::currentChanged,selectPageWidget,&selectPage::tabCurrentChanged);
    connect(tabWidget,&QTabWidget::currentChanged,deletePageWidget,&deletePage::tabCurrentChanged);
    connect(tabWidget,&QTabWidget::currentChanged,updatePageWidget,&updatePage::tabCurrentChanged);
    connect(tabWidget,&QTabWidget::currentChanged,statePageWidget,&statePage::tabCurrentChanged);

    this->setWindowTitle("密接者信息管理系统");
    this->resize(1000, 300);
}

contactData myMainWindow::getcontactInfoByName(QString name1)
{
    contactData res;
    if(!name1.isEmpty() && name1.length()>0){
       getcontactList();
       if(!_contactDataList.isEmpty() && _contactDataList.count()>0)
       {
           for (int js=0;js<_contactDataList.count();js++) {
             contactData sd0=_contactDataList[js];
             if(sd0.getcontact_name()==name1)
             {
                 res=sd0;
                 break;
             }
           }
       }
    }
    return res;
}

bool myMainWindow::insertcontactInfo(contactData sd1)
{
    bool res=false;
    if(!sd1.getcontact_no().isEmpty()){
       getcontactList();
       int index=-1;
       for(int js=0;js<_contactDataList.count();js++){
           if(sd1.getcontact_no()==_contactDataList[js].getcontact_no())
           {
               index=js; //存在该身份证号
               break;
           }
       }
       if(index<0){
         _contactDataList.append(sd1);
       }
       else
       {
          _contactDataList[index]=sd1;
       }
      fileUtil* fu1=new fileUtil(this);
      fu1->writecontactData(_contactDataList);
       res=true;
    }
    return res;
}

bool myMainWindow::deletecontactInfo(QString no1)
{
    bool res=false;
    if(!no1.isEmpty())
    {
        getcontactList();
        int index=-1;
        for(int js=0;js<_contactDataList.count();js++){
            if(no1==_contactDataList[js].getcontact_no())
            {
                index=js; //存在该学号的学生
                break;
            }
        }
        if(index>=0){
          _contactDataList.removeAt(index);
        }
       fileUtil* fu1=new fileUtil(this);
       fu1->writecontactData(_contactDataList);
       res=true;
    }
    return res;
}


QList<contactData> myMainWindow::getcontactList()
{
     fileUtil* fu1=new fileUtil(this);
    _contactDataList= fu1->readcontactData();
    return _contactDataList;
}

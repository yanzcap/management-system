#include "deletepage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"

deletePage::deletePage(QWidget *parent) : QWidget(parent)
{
    this->_mainWindow=(myMainWindow*)parent;
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("密接者信息删除");
    titleLabel->setAlignment(Qt::AlignCenter);
    comBox=new QComboBox(this);
    comboAddData();
    QPushButton* deleteBtn=new QPushButton(this);
    deleteBtn->setText("删除");
    QLabel* noLabel=new QLabel(this);
    noLabel->setText("身份证号：");
    QLabel* nameLabel=new QLabel(this);
    nameLabel->setText("姓名：");
    QLabel* sexLabel=new QLabel(this);
    sexLabel->setText("性别：");
    QLabel* ageLabel=new QLabel(this);
    ageLabel->setText("年龄：");
    QLabel* majorLabel=new QLabel(this);
    majorLabel->setText("隔离点：");
    QLabel* temLabel=new QLabel(this);
    temLabel->setText("当日体温：");
    noEdit=new QLineEdit(this);
    nameEdit=new QLineEdit(this);
    sexEdit=new QLineEdit(this);
    ageEdit=new QLineEdit(this);
    majorEdit=new QLineEdit(this);
    temEdit=new QLineEdit(this);
    noEdit->setEnabled(false);
    nameEdit->setEnabled(false);
    sexEdit->setEnabled(false);
    ageEdit->setEnabled(false);
    majorEdit->setEnabled(false);
    temEdit->setEnabled(false);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10);   //设置单元间隔
    gridLayout->setMargin(20);    //设置边距
    gridLayout->addWidget(titleLabel,0,0,1,4);
    gridLayout->addWidget(comBox,1,0,1,2);
    gridLayout->addWidget(deleteBtn,1,3,1,1);
    gridLayout->addWidget(noLabel,2,0,1,1);
    gridLayout->addWidget(noEdit,2,1,1,1);
    gridLayout->addWidget(nameLabel,2,2,1,1);
    gridLayout->addWidget(nameEdit,2,3,1,1);
    gridLayout->addWidget(sexLabel,3,0,1,1);
    gridLayout->addWidget(sexEdit,3,1,1,1);
    gridLayout->addWidget(ageLabel,3,2,1,1);
    gridLayout->addWidget(ageEdit,3,3,1,1);
    gridLayout->addWidget(majorLabel,4,0,1,1);
    gridLayout->addWidget(majorEdit,4,1,1,1);
    gridLayout->addWidget(temLabel,4,2,1,1);
    gridLayout->addWidget(temEdit,4,3,1,1);
    this->setLayout(gridLayout);
    this->resize(1000, 300);
    currentIndexChanged(0);
    connect(deleteBtn,&QPushButton::clicked,this,&deletePage::deleteBtnClicked);
    connect(comBox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChanged(int)));
}

void deletePage::deleteBtnClicked()
{
   int btnIndex= QMessageBox::warning(NULL, "warning", "确定要删除这个密接者信息吗？",
            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
   if(btnIndex==QMessageBox::Yes){
       bool res=this->_mainWindow->deletecontactInfo(comBox->currentData().toString());
       if(res)
       {
           QMessageBox::about(this,"提醒","密接者信息删除成功！");
           comboAddData();
           currentIndexChanged(0);
       }
       else QMessageBox::about(this,"提醒","密接者信息删除失败！");
   }
}

void deletePage::tabCurrentChanged(int index)
{
   comboAddData();
    currentIndexChanged(0);
}

void deletePage::currentIndexChanged(int index)
{
    qDebug()<<comBox->currentText();
    contactData sd0=this->_mainWindow->getcontactInfoByName(comBox->currentText());
    //if(sd0!=NULL)
    //{
       noEdit->setText(sd0.getcontact_no());
       nameEdit->setText(sd0.getcontact_name());
       sexEdit->setText(sd0.getcontact_sex());
       ageEdit->setText(sd0.getcontact_age());
       majorEdit->setText(sd0.getcontact_major());
       temEdit->setText(sd0.getcontact_tem());
       //}
}

void deletePage::comboAddData()
{
    fileUtil* fu1=new fileUtil(this);
    //fu1->writeFile("test.txt",ss);
    QList<contactData> res= fu1->readcontactData();
    if(!res.isEmpty() && res.count()>0)
    {
        comBox->clear();
        for(int js=0;js<res.count();js++)
        {
            contactData tmp=res[js];
            comBox->addItem(tmp.getcontact_name(),tmp.getcontact_no());
        }
    }
}

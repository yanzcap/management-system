#include "insertpage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"

insertPage::insertPage(QWidget *parent) : QWidget(parent)
{
    this->_mainWindow=(myMainWindow*)parent;
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("密接者信息添加");
    titleLabel->setAlignment(Qt::AlignCenter);
    QPushButton*  insertBtn=new QPushButton(this);
    insertBtn->setText("添加");
    QPushButton*  resetBtn=new QPushButton(this);
    resetBtn->setText("重置");
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

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10);   //设置单元间隔
    gridLayout->setMargin(20);    //设置边距
    gridLayout->addWidget(titleLabel,0,0,1,4);
    gridLayout->addWidget(insertBtn,1,0,1,2);
    gridLayout->addWidget(resetBtn,1,2,1,2);
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
    connect(insertBtn,&QPushButton::clicked,this,&insertPage::insertBtnClicked);
    connect(resetBtn,&QPushButton::clicked,this,&insertPage::resetBtnClicked);
}

void insertPage::insertBtnClicked()
{
    if(noEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入身份证号！");
        return;
    }
    else if(nameEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入姓名！");
        return;
    }
    else if(sexEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入性别！");
        return;
    }
    else if(ageEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入年龄！");
        return;
    }
    else if(majorEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入隔离点！");
        return;
    }
    else if(temEdit->text().isEmpty())
    {
        QMessageBox::about(this,"提醒","请输入体温！");
        return;
    }
    QStringList* contactTmp=new QStringList();
    contactTmp->append(noEdit->text());
    contactTmp->append(nameEdit->text());
    contactTmp->append(sexEdit->text());
    contactTmp->append(ageEdit->text());
    contactTmp->append(majorEdit->text());
    contactTmp->append(temEdit->text());
    contactData* sd0=new contactData(*contactTmp);
    bool res=this->_mainWindow->insertcontactInfo(*sd0);
    if(res)QMessageBox::about(this,"提醒","密接者信息添加成功！");
    else QMessageBox::about(this,"提醒","密接者信息添加失败！");
}

void insertPage::resetBtnClicked()
{
    noEdit->setText("");
    nameEdit->setText("");
    sexEdit->setText("");
    ageEdit->setText("");
    majorEdit->setText("");
    temEdit->setText("");
}


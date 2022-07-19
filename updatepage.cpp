#include "updatepage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"

updatePage::updatePage(QWidget *parent) : QWidget(parent)
{
    this->_mainWindow=(myMainWindow*)parent;
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("密接者信息修改");
    titleLabel->setAlignment(Qt::AlignCenter);
    comBox=new QComboBox(this);
    comboAddData();
    QPushButton* updateBtn=new QPushButton(this);
    updateBtn->setText("保存");
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

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10);   //设置单元间隔
    gridLayout->setMargin(20);    //设置边距
    gridLayout->addWidget(titleLabel,0,0,1,4);
    gridLayout->addWidget(comBox,1,0,1,2);
    gridLayout->addWidget(updateBtn,1,3,1,1);
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
    connect(updateBtn,&QPushButton::clicked,this,&updatePage::updateBtnClicked);
    connect(comBox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChanged(int)));
}

void updatePage::tabCurrentChanged(int index)
{
    comboAddData();
    currentIndexChanged(0);
}

void updatePage::currentIndexChanged(int index)
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

void updatePage::updateBtnClicked()
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
    if(res)
    {
        QMessageBox::about(this,"提醒","密切接触者信息修改成功！");
        comboAddData();
        currentIndexChanged(0);
    }
    else QMessageBox::about(this,"提醒","密切接触者信息修改失败！");
}

void updatePage::comboAddData()
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

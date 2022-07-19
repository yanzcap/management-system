#include "statepage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"

statePage::statePage(QWidget *parent) : QWidget(parent)
{
    this->_mainWindow=(myMainWindow*)parent;
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("防疫信息存储");
    titleLabel->setAlignment(Qt::AlignCenter);
    comBox=new QComboBox(this);
    comboAddData();
    QPushButton* stateBtn=new QPushButton(this);
    stateBtn->setText("保存");
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

    QLabel* Label1=new QLabel(this);
    Label1->setText("今日核酸结果：");
    QLabel* Label2=new QLabel(this);
    Label2->setText("疫苗接种：");
    QLabel* Label3=new QLabel(this);
    Label3->setText("是否确诊：");
    comBox1=new QComboBox(this);
    comBox1->addItem(tr("阴性"));
    comBox1->addItem(tr("阳性"));
    comBox2=new QComboBox(this);
    comBox2->addItem(tr("未接种"));
    comBox2->addItem(tr("已接种一针"));
    comBox2->addItem(tr("已接种二针"));
    comBox2->addItem(tr("已接种加强针"));
    comBox3=new QComboBox(this);
    comBox3->addItem(tr("否"));
    comBox3->addItem(tr("是"));

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10);   //设置单元间隔
    gridLayout->setMargin(20);    //设置边距
    gridLayout->addWidget(titleLabel,0,0,1,4);
    gridLayout->addWidget(comBox,1,0,1,2);
    gridLayout->addWidget(stateBtn,1,3,1,1);
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
    gridLayout->addWidget(Label1,5,0,1,1);
    gridLayout->addWidget(comBox1,5,1,1,1);
    gridLayout->addWidget(Label2,5,2,1,1);
    gridLayout->addWidget(comBox2,5,3,1,1);
    gridLayout->addWidget(Label3,6,0,1,1);
    gridLayout->addWidget(comBox3,6,1,1,1);

    this->setLayout(gridLayout);
    this->resize(1000, 300);
    currentIndexChanged(0);
    connect(stateBtn,&QPushButton::clicked,this,&statePage::stateBtnClicked);
    connect(comBox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChanged(int)));
}

void statePage::tabCurrentChanged(int index)
{
    comboAddData();
    currentIndexChanged(0);
}

void statePage::currentIndexChanged(int index)
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

void statePage::stateBtnClicked()
{
    FILE *fp=NULL;
    fp=fopen("E:/contactMIS/res/state.txt","a");

    QString number;
    QString name;
    QString test;
    QString vaccine;
    QString diagnose;

    number=noEdit->text();
    std::string str=number.toStdString();
    const char* ch=str.c_str();
    fprintf(fp,ch);fprintf(fp," , ");

    name=nameEdit->text();
    str=name.toStdString();
    ch=str.c_str();
    fprintf(fp,ch);fprintf(fp," , ");

    test=comBox1->currentText();
    str=test.toStdString();
    ch=str.c_str();
    fprintf(fp,ch);fprintf(fp," , ");

    vaccine=comBox2->currentText();
    str=vaccine.toStdString();
    ch=str.c_str();
    fprintf(fp,ch);fprintf(fp," , ");

    diagnose=comBox3->currentText();
    str=diagnose.toStdString();
    ch=str.c_str();
    fprintf(fp,ch);fprintf(fp,"\n");

    QMessageBox::about(this,"提醒","此密切接触者防疫信息添加成功！");
    fclose(fp);
}

void statePage::comboAddData()
{
    fileUtil* fu1=new fileUtil(this);
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

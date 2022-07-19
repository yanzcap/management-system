#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->mparent=parent;
    QVBoxLayout* vlay=new QVBoxLayout(this);
    QHBoxLayout* hlay1=new QHBoxLayout(this);
    QHBoxLayout* hlay2=new QHBoxLayout(this);
    QHBoxLayout* hlay3=new QHBoxLayout(this);
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("欢迎进入密接者信息管理系统");
    titleLabel->setAlignment(Qt::AlignCenter);
    QLabel* userLabel=new QLabel(this);
    userLabel->setText("用户名：");
    QLabel* passwordLabel=new QLabel(this);
    passwordLabel->setText("密  码：");
    userEdit=new QLineEdit(this);
    passwordEdit=new QLineEdit(this);
    QLabel* checkLabel=new QLabel(this);
    checkLabel->setText("隐藏密码:");
    check=new QCheckBox(this);
    QPushButton* loginBtn=new QPushButton(this);
    loginBtn->setText("登录");
    QPushButton* exitBtn=new QPushButton(this);
    exitBtn->setText("退出");
    hlay1->addWidget(userLabel);
    hlay1->addWidget(userEdit);
    hlay2->addWidget(passwordLabel);
    hlay2->addWidget(passwordEdit);
    hlay2->addWidget(checkLabel);
    hlay2->addWidget(check);
    hlay3->addWidget(loginBtn);
    hlay3->addWidget(exitBtn);
    vlay->addWidget(titleLabel);
    vlay->addItem(hlay1);
    vlay->addItem(hlay2);
    vlay->addItem(hlay3);
    this->setLayout(vlay);
    this->resize(500,200);
    connect(loginBtn,&QPushButton::clicked,this,&Dialog::loginBtnClicked);
    connect(exitBtn,&QPushButton::clicked,this,&Dialog::exitBtnClicked);
    connect(check,&QCheckBox::stateChanged,this,&Dialog::on_check_clicked);
}

Dialog::~Dialog()
{
}

void Dialog::loginBtnClicked()
{

   QString user0=userEdit->text();
   QString password0=passwordEdit->text();
   if(user0==NULL || user0.length()<=0)
   {
      QMessageBox::about(this,"警告","请输入用户名！");
      return;
   }
   else if(password0==NULL || password0.length()<=0)
   {
      QMessageBox::about(this,"警告","请输入密码！");
      return;
   }


   fileUtil* fu1=new fileUtil(this);
   QList<userInfoData> userList=fu1->readUserinfoData();

   if(!userList.isEmpty() && userList.length()>0 &&  userList[0].getUsername()==user0 && userList[0].getPassword()==password0)
   {
       this->mparent->show();
       exitBtnClicked();
   }
   else
       QMessageBox::about(this,"警告","用户名或密码错误，请重新输入！");

}

void Dialog::exitBtnClicked()
{
   this->close();
}

void Dialog::on_check_clicked()
{
    if(check->isChecked())
            passwordEdit->setEchoMode(QLineEdit::Password);
        else
            passwordEdit->setEchoMode(QLineEdit::Normal);
}

#include "modifyuserinfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>
#include <QMessageBox>
#include "fileutil.h"
#include "userinfodata.h"

modifyUserInfo::modifyUserInfo(QWidget *parent) : QWidget(parent)
{
    this->_mainWindow=(myMainWindow*)parent;
    QVBoxLayout* vlay=new QVBoxLayout(this);
    QHBoxLayout* hlay1=new QHBoxLayout(this);
    QHBoxLayout* hlay2=new QHBoxLayout(this);
    QHBoxLayout* hlay3=new QHBoxLayout(this);
    QLabel* titleLabel=new QLabel(this);
    titleLabel->setText("修改用户信息");
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
    QPushButton* saveBtn=new QPushButton(this);
    saveBtn->setText("保存");
    hlay1->addWidget(userLabel);
    hlay1->addWidget(userEdit);
    hlay2->addWidget(passwordLabel);
    hlay2->addWidget(passwordEdit);
    hlay2->addWidget(checkLabel);
    hlay2->addWidget(check);
    hlay3->addWidget(saveBtn);
    vlay->addWidget(titleLabel);
    vlay->addItem(hlay1);
    vlay->addItem(hlay2);
    vlay->addItem(hlay3);
    this->setLayout(vlay);
    this->resize(500,200);
    connect(saveBtn,&QPushButton::clicked,this,&modifyUserInfo::saveBtnClicked);
    connect(check,&QCheckBox::stateChanged,this,&modifyUserInfo::on_check_clicked);
}

void modifyUserInfo::saveBtnClicked()
{
    int btnIndex= QMessageBox::warning(NULL, "warning", "确定要修改用户信息吗？",
             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(btnIndex==QMessageBox::Yes){
        QString username=userEdit->text();
        QString password=passwordEdit->text();
        fileUtil* fu1=new fileUtil(this);
        QStringList* userstr=new QStringList();
        userstr->append(username);
        userstr->append(password);
        userInfoData* ud0=new userInfoData(*userstr);
        QList<userInfoData>* udList=new QList<userInfoData>();
        udList->append(*ud0);
        bool res=fu1->writeUserinfoData(*udList);
        if(res)
        {
            QMessageBox::about(this,"提醒","用户信息修改成功！");
        }
        else QMessageBox::about(this,"提醒","用户信息修改失败！");
    }
}

void modifyUserInfo::on_check_clicked()
{
    if(check->isChecked())
            passwordEdit->setEchoMode(QLineEdit::Password);
        else
            passwordEdit->setEchoMode(QLineEdit::Normal);
}

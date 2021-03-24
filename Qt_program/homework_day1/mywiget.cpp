#include "mywiget.h"
#include "qpushbutton.h"
#include "mypushbutton.h"
#include <QDebug>

//ctrl+r 运行
//ctrl+/ 注释
//ctrl+b 编译
//ctrl+shift+↑ 整行移动
//同名之间.h and .cpp 之间的切换
//帮助文档F1

mywidget::mywidget(QWidget *parent)
    : QWidget(parent)
{
    //创建第一个按钮
    QPushButton *btn = new QPushButton;
    btn->setParent(this);//设置对象树
    btn->setText("第一个按钮");//添加文本
    //创建第二个按钮,使用有参构造的方式，一步到位
    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    resize(600,400);//重置窗口大小
    btn2->move(100,100);//移动按钮
    btn2->resize(200,50);//重新构造按钮大小
    setWindowTitle("第一个窗口");
    setFixedSize(600,400);
    myPushButton *myBtn = new myPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(222,333);
    myBtn->setParent(this);  //设置到对象树当中

    //参数一：信号的发送者  参数二：发送的信号  参数三：信号的接收者  参数四：处理槽函数
    connect(myBtn, QPushButton::clicked, this, mywidget::close);
}




mywidget::~mywidget()
{
    qDebug() << "mywiget的析构调用";
}

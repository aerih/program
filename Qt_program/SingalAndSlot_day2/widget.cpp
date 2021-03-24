#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->zt = new Teacher(this);
    this->st = new Student(this);
    //void( Teacher:: * teacherSignal )( QString ) = &Teacher::hungry;
    //void( Student:: * studentSlot)( QString ) = &Student::treat;
    connect(zt, &Teacher::hungry, st, &Student::treat);
    //连接带参数的信号和槽  ，函数指针->函数地址
    //connect(zt,teacherSignal,st,studentSlot);
    classIsOver();

//    QPushButton* btn = new QPushButton("下课", this);
//    //重置窗口大小
//    this->resize(600,400);
//    connect(btn, &QPushButton::clicked, this ,&Widget::classIsOver);
}
void Widget::classIsOver()
{
    emit zt->hungry();
    //emit zt->hungry("宫保鸡丁");
}


Widget::~Widget()
{
    delete ui;
}

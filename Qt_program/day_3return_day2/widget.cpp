#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->zt = new Teacher(this);
    this->st = new Student(this); //使用有参构造的方式，加入到了对象树当中
//    connect(zt, &Teacher::hungry, st ,&Student::treat);
//    classIsOver();
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlots)(QString) = &Student::treat;
    connect(zt, teacherSignal, st,studentSlots);
    classIsOver();
}
void Widget::classIsOver()
{
    emit zt->hungry("Qt");
}

Widget::~Widget()
{
    delete ui;
}

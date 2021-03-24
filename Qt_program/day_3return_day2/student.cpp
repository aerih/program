#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()  //成员函数一定要加作用域
{
    qDebug() << "老师饿了，学生请吃饭";
}

void Student::treat(QString className)
{
    qDebug() << "今天想学什么？" << className.toUtf8().data();
}

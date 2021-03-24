#include "mypushbutton.h"
#include <QDebug>

myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用";
}

myPushButton::~myPushButton()
{
    qDebug() << "mypushbutton析构结束";
}

#include "mywiget.h"
#include <QApplication> //包含一个应用程序的类的头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  //应用程序对象，有且只有一个
    mywidget w;
    //窗口对象
    w.show();

    return a.exec();
}

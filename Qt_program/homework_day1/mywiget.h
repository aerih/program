#ifndef MYWIGET_H
#define MYWIGET_H

#include <QWidget>

class mywidget : public QWidget
{
    Q_OBJECT

public:
    mywidget(QWidget *parent = 0);
    ~mywidget();
};

#endif // MYWIGET_H

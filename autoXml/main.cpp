#include "widget.h"
#include <QApplication>

class A
{
class B
{

};
};

class B
{

};

class C
{
    class B{};
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}


#include "ruleswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RulesWindow rule;
    rule.show();
    return a.exec();
}

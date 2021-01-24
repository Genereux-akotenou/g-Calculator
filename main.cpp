#include "mainapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainApp myCalculator;
    myCalculator.show();

    return app.exec();
}

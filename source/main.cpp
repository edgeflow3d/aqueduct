#include <QApplication>
#include <QSettings>
#include <QFontDatabase>

#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Edgeflow");
    QCoreApplication::setOrganizationDomain("edgeflow.net");
    QCoreApplication::setApplicationName("Aqueduct");

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/aqueduct_logo_32.png"));

    QFontDatabase::addApplicationFont(":/fonts/AD_Montserrat-Medium.ttf");

    MainWindow main;
    main.show();

    return app.exec();
}

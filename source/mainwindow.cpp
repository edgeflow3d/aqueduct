#include <QtWidgets>
#include <QSettings>

#include "mainwindow.h"
#include "librarybrowser.h"
#include "assetbrowser.h"

MainWindow::MainWindow() :
    QMainWindow() 
{
    QSettings settings;

    qDebug() << settings.allKeys();

    setWindowTitle("Aqueduct - Alpha v0.1");
    resize(1350, 850);

    createActions();
    createSplits();
    ensurePolished();
    loadStyleSheet("default");

    statusBar()->showMessage("Ready");
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu("&File");
    /* QToolBar *fileToolBar = addToolBar("File"); */

    QAction *quitAct = new QAction("&Quit", this);
    quitAct->setShortcut(QKeySequence::Quit);
    quitAct->setStatusTip("Quit Asset Manager");

    connect(quitAct, &QAction::triggered, this, &QApplication::exit);

    fileMenu->addAction(quitAct);
}

void MainWindow::createSplits()
{
    LibraryBrowser *librarybrowser = new LibraryBrowser(this);
    AssetBrowser *assetbrowser = new AssetBrowser(this);

    QSplitter *split = new QSplitter(this);
    split->addWidget(librarybrowser);
    split->addWidget(assetbrowser);
    split->setStretchFactor(0, 1);
    split->setStretchFactor(1, 4);

    setCentralWidget(split);

    connect(librarybrowser, &LibraryBrowser::clicked,
            assetbrowser, &AssetBrowser::on_treeview_clicked);

}

void MainWindow::loadStyleSheetFromFile(const QString &sheetPath)
{
    if (QFile::exists(sheetPath))
    {
        QFile file(sheetPath);
        file.open(QFile::ReadOnly);
        QString styleSheet = QString::fromLatin1(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }

}

void MainWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/qss/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    qApp->setStyleSheet(styleSheet);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "Quitting Aqueduct";
    event->accept();
}

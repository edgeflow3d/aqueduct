#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow 
{
    Q_OBJECT

    public:
        MainWindow();

    protected:
        void paintEvent(QPaintEvent *);

    private:
        void createActions();
        void createSplits();
        void loadStyleSheetFromFile(const QString &sheetPath);
        void loadStyleSheet(const QString &sheetName);

        void closeEvent(QCloseEvent *event);
};

#endif //MAINWINDOW_H

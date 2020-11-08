#ifndef LIBRARYBROWSER_H
#define LIBRARYBROWSER_H

#include <QtWidgets>

class LibraryBrowser : public QWidget
{
    Q_OBJECT

    public:
        explicit LibraryBrowser(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *);

    signals:
        void clicked(const QModelIndex &index);

    private slots:
        void on_addBtn_pressed();

    private:
        QPushButton *addBtn;
        QTreeView *treeview;
        QFileSystemModel *model;

};

#endif //LIBRARYBROWSER_H

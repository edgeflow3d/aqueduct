#include "librarybrowser.h"
#include "libraryviewmodel.h"

#include <QtWidgets>
#include <QDebug>

LibraryBrowser::LibraryBrowser(QWidget *parent)
    : QWidget(parent)
{
    QSettings settings;

    addBtn = new QPushButton(this);
    addBtn->setText("Set library folder");

    connect(addBtn, &QPushButton::clicked, this, &LibraryBrowser::on_addBtn_pressed);

    model = new LibraryViewModel(this);
    model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    model->setRootPath(QDir::rootPath());

    treeview = new QTreeView(this);

    treeview->setModel(model);
    /* treeview->setRootIndex(model->index("/")); */
    if (!settings.value("librarybrowser/rootPath").isNull())
    {
        qDebug() << "rootPath default available";
        treeview->setRootIndex(model->index(settings.value("librarybrowser/rootPath").toString()));
    }

    // hide all columns except name and then hide header
    treeview->header()->hideSection(1);
    treeview->header()->hideSection(2);
    treeview->header()->hideSection(3);
    treeview->setHeaderHidden(true);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(addBtn);
    vbox->addWidget(treeview);

    connect(treeview, &QTreeView::clicked,
            this, &LibraryBrowser::clicked);

}

void LibraryBrowser::on_addBtn_pressed()
{
    qDebug() << "Set library folder";
    QString dir = QFileDialog::getExistingDirectory(
            this,
            "Open Directory",
            "/home",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
            );
    treeview->setRootIndex(model->index(dir));

    QSettings settings;
    settings.setValue("librarybrowser/rootPath", dir);
}

void LibraryBrowser::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

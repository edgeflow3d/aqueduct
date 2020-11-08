#include "libraryviewmodel.h"
#include <QDebug>

LibraryViewModel::LibraryViewModel(QObject *parent)
    : QFileSystemModel(parent)
{
    qDebug() << "libraryviewmodel created";
}

bool LibraryViewModel::hasChildren(const QModelIndex &parent) const
{
    // return false if item cant have children
    if (parent.flags() &Qt::ItemNeverHasChildren)
        return false;

    // return if at least one child exists
    return QDirIterator(
            filePath(parent),
            filter() | QDir::NoDotAndDotDot,
            QDirIterator::NoIteratorFlags
            ).hasNext();

}

QVariant LibraryViewModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DecorationRole)
    {
        QFileInfo info = this->fileInfo(index);

        if(info.isDir())
        {
            QPixmap foldericon;
            foldericon.load(":/images/icon_folder.png");
            return foldericon;
        }
    }
    return QFileSystemModel::data(index, role);
}

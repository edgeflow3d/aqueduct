#ifndef LIBRARYVIEWMODEL_H
#define LIBRARYVIEWMODEL_H

#include <QFileSystemModel>

class LibraryViewModel : public QFileSystemModel
{
    Q_OBJECT

    public:
        LibraryViewModel(QObject *parent = 0);
        QVariant data(const QModelIndex &index, int role) const;

    private:
        bool hasChildren(const QModelIndex &parent) const;
};

#endif //LIBRARYVIEWMODEL_H

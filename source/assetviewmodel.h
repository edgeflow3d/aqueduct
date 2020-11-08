#ifndef ASSETVIEWMODEL_H
#define ASSETVIEWMODEL_H

#include <QFileSystemModel>
#include <QDropEvent>

class AssetViewModel : public QFileSystemModel
{
    Q_OBJECT

    public:
        explicit AssetViewModel(QObject *parent = 0);

        QVariant data(const QModelIndex &index, int role) const;
        void setTileSize(int value);

    public slots:
        void on_tilesizeChanged(int value);

    private:
        int tilesize;

};

#endif //ASSETVIEWMODEL_H

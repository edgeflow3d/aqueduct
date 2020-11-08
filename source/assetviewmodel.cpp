#include "assetviewmodel.h"
#include <QDebug>
#include <QFileSystemModel>
#include <QPixmapCache>
#include <iostream>

AssetViewModel::AssetViewModel(QObject *parent)
    : QFileSystemModel(parent)
{
    qDebug() << "assetviewmodel created";
    tilesize = 300;
}

QVariant AssetViewModel::data( const QModelIndex &index, int role) const {
    if (role == Qt::DecorationRole)
    {
        QFileInfo info = this->fileInfo(index);

        if(info.isFile())
        {
            if(info.suffix() == "blend")
            {
                QString thumbnail_path = "";

                QString filebasepath = info.path() + QDir::separator() + info.baseName();

                // look for jpg or png preview image
                if (QFile::exists(filebasepath + ".png"))
                    thumbnail_path = filebasepath + ".png";
                else if (QFile::exists(filebasepath + ".jpg"))
                    thumbnail_path = filebasepath + ".jpg";

                // create the pixmap for the preview
                QPixmapCache::setCacheLimit(512000);
                QPixmap thumbnail;
                if (thumbnail_path != "")
                {
                    QString key = info.fileName().replace(" ", "_").toLower();
                    if (!QPixmapCache::find(key, &thumbnail)) {
                        thumbnail.load(thumbnail_path);
                        QPixmapCache::insert(key, thumbnail);
                        }
                }
                else
                    thumbnail.load(":/images/3d_asset.png");


                thumbnail = thumbnail.scaled(tilesize-16,
                                             tilesize-16,
                                             Qt::KeepAspectRatio,
                                             Qt::SmoothTransformation);
                return thumbnail;
            }

        }
    }
    return QFileSystemModel::data(index, role);
}

void AssetViewModel::setTileSize(int value)
{
    tilesize = value;
}


void AssetViewModel::on_tilesizeChanged(int value)
{
    setTileSize(value);
}

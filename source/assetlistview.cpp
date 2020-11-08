#include "assetlistview.h"

#include <QDebug>
#include <QScrollBar>

AssetListView::AssetListView(QWidget *parent)
    : QListView(parent)
{
    qDebug() << "AssetListView created";
    // Change scrollbar step for smoother scrolling
    QScrollBar *qVertScroll = this->verticalScrollBar();
    qVertScroll->setPageStep(25);
    qVertScroll->setSingleStep(25);

    // enable batching
    setLayoutMode(QListView::Batched);
    setBatchSize(10);
}

void AssetListView::on_tilesizeChanged(int value)
{
   setGridSize(QSize(value, value * 1.12));
}

void AssetListView::dropEvent(QDropEvent *e)
{
    return;
}

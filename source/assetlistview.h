#ifndef ASSETLISTVIEW_H
#define ASSETLISTVIEW_H

#include <QListView>

class AssetListView : public QListView
{
    Q_OBJECT

    public:
        AssetListView(QWidget *parent = 0);

    public slots:
        void on_tilesizeChanged(int value);

    protected:
        void dropEvent(QDropEvent *e) override;
};


#endif //ASSETLISTVIEW_H

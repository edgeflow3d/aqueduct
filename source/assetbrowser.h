#ifndef ASSETBROWSER_H
#define ASSETBROWSER_H

#include <QtWidgets>
#include "assetlistview.h"
#include "assetviewmodel.h"

class AssetBrowser : public QWidget
{
    Q_OBJECT

    public:
        explicit AssetBrowser(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *);

    public slots:
        void on_treeview_clicked(const QModelIndex &index);

    private:
        AssetListView *listview;
        AssetViewModel *model;
        QStringList filefilters;
        
};

#endif //ASSETVIEWAREA_H

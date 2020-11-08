#include "assetbrowser.h"
#include "assetviewmodel.h"
#include "assetlistview.h"

AssetBrowser::AssetBrowser(QWidget *parent) :
    QWidget(parent)
{
    int tilesize = 500;

    listview = new AssetListView(this);
    model = new AssetViewModel(this);

    model->setFilter(QDir::Files | QDir::NoDotAndDotDot );
    model->setRootPath("/");

    filefilters << "*.blend";

    model->setNameFilters(filefilters);
    model->setNameFilterDisables(false);

    listview->setModel(model);
    listview->setRootIndex(model->index("/"));
    listview->setSelectionMode(QAbstractItemView::ExtendedSelection);
    listview->setDragEnabled(true);
    listview->setDropIndicatorShown(true);
    listview->setMovement(QListView::Snap);

    listview->setViewMode(QListView::ViewMode::IconMode);
    listview->setFlow(QListView::LeftToRight);
    listview->setResizeMode(QListView::Adjust);

    listview->setGridSize(QSize(300, 300 * 1.12));
    listview->setWrapping(true);

    QSlider *tilesize_slider = new QSlider(Qt::Horizontal, this);
    tilesize_slider->setMinimumWidth(150);
    tilesize_slider->setMinimum(150);
    tilesize_slider->setMaximum(tilesize);
    tilesize_slider->setValue(300);
    // QSS style sheets and tickmarks don't work together
    /* tilesize_slider->setTickInterval(50); */
    /* tilesize_slider->setTickPosition(QSlider::TicksBelow); */
    tilesize_slider->setSingleStep(50);
    tilesize_slider->setPageStep(50);


    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(tilesize_slider);
    hbox->addStretch(1);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(listview);
    vbox->addLayout(hbox);

    setLayout(vbox);

    // Signal Slots | tilesize slider
    connect(tilesize_slider, &QSlider::valueChanged,
            listview, &AssetListView::on_tilesizeChanged);
    connect(tilesize_slider, &QSlider::valueChanged,
            model, &AssetViewModel::on_tilesizeChanged);
}

void AssetBrowser::on_treeview_clicked(const QModelIndex &index)
{
    QString mPath = model->fileInfo(index).absoluteFilePath();

    listview->setRootIndex(model->setRootPath(mPath));
   
    // resetting the filters to prevent visited subfolders from being displayed(bug/hackfix)
    model->setNameFilters(filefilters);
    model->setNameFilterDisables(false);
}

void AssetBrowser::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

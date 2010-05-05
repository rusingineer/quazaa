#include "widgetgraph.h"
#include "ui_widgetgraph.h"

#include "quazaasettings.h"
#include "QSkinDialog/qskinsettings.h"

WidgetGraph::WidgetGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WidgetGraph)
{
    ui->setupUi(this);
	connect(&skinSettings, SIGNAL(skinChanged()), this, SLOT(skinChangeEvent()));
	skinChangeEvent();
	ui->splitterGraph->restoreState(quazaaSettings.WinMain.GraphSplitter);
}

WidgetGraph::~WidgetGraph()
{
    delete ui;
	quazaaSettings.WinMain.GraphSplitter = ui->splitterGraph->saveState();
}

void WidgetGraph::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void WidgetGraph::skinChangeEvent()
{
	ui->toolBarControls->setStyleSheet(skinSettings.toolbars);
}

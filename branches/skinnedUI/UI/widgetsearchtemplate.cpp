//
// widgetsearchtemplate.cpp
//
// Copyright � Quazaa Development Team, 2009-2010.
// This file is part of QUAZAA (quazaa.sourceforge.net)
//
// Quazaa is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// Quazaa is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Quazaa; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "widgetsearchtemplate.h"
#include "ui_widgetsearchtemplate.h"
#include <QSortFilterProxyModel>

#include "QSkinDialog/qskinsettings.h"

#include "NetworkCore/searchmanager.h"
#include "NetworkCore/managedsearch.h"
#include "NetworkCore/query.h"
#include "NetworkCore/queryhit.h"

WidgetSearchTemplate::WidgetSearchTemplate(QString searchString, QWidget* parent) :
	QWidget(parent),
	ui(new Ui::WidgetSearchTemplate)
{
	ui->setupUi(this);
	sSearchString = searchString;
	m_pSearch = 0;
	nFiles = 0;
	nHits = 0;
	nHubs = 0;
	nLeaves = 0;
	searchState = SearchState::Stopped;
	QSortFilterProxyModel* sortModel = new QSortFilterProxyModel(this);
	searchModel = new SearchTreeModel();
	sortModel->setSourceModel(searchModel);
	ui->treeViewSearchResults->setModel(sortModel);
	sortModel->setDynamicSortFilter(true);
	connect(&skinSettings, SIGNAL(skinChanged()), this, SLOT(skinChangeEvent()));
	connect(searchModel, SIGNAL(updateStats()), this, SLOT(OnStatsUpdated()));
	skinChangeEvent();
}

WidgetSearchTemplate::~WidgetSearchTemplate()
{
	if(m_pSearch != 0)
	{
		StopSearch();
	}
	delete ui;
}

void WidgetSearchTemplate::changeEvent(QEvent* e)
{
	QWidget::changeEvent(e);
	switch(e->type())
	{
		case QEvent::LanguageChange:
			ui->retranslateUi(this);
			break;
		default:
			break;
	}
}

void WidgetSearchTemplate::StartSearch(CQuery* pQuery)
{
	if(m_pSearch && m_pSearch->m_pQuery != pQuery)
	{
		delete m_pSearch;
		m_pSearch = 0;
	}

	if(!m_pSearch)
	{
		m_pSearch = new CManagedSearch(pQuery);
		connect(m_pSearch, SIGNAL(OnHit(QueryHitSharedPtr)), searchModel, SLOT(addQueryHit(QueryHitSharedPtr)));
		connect(m_pSearch, SIGNAL(StatsUpdated()), this, SLOT(OnStatsUpdated()));
	}

	m_pSearch->Start();
	searchState = SearchState::Searching;
	sSearchString = m_pSearch->m_pQuery->DescriptiveName();
}

void WidgetSearchTemplate::StopSearch()
{
	Q_ASSERT(m_pSearch != 0);

	m_pSearch->Stop();
	delete m_pSearch;
	m_pSearch = 0;
	searchState = SearchState::Stopped;
}

void WidgetSearchTemplate::PauseSearch()
{
	Q_ASSERT(m_pSearch != 0);

	m_pSearch->Pause();
	searchState = SearchState::Paused;
}

void WidgetSearchTemplate::ClearSearch()
{
	qDebug() << "Clear search captured in widget search template.";
	searchModel->clear();
	qApp->processEvents();
}

void WidgetSearchTemplate::OnStatsUpdated()
{
	nFiles = searchModel->nFileCount;
	nHits = m_pSearch->m_nHits;
	nHubs = m_pSearch->m_nHubs;
	nLeaves = m_pSearch->m_nLeaves;
	emit statsUpdated(this);
}

void WidgetSearchTemplate::skinChangeEvent()
{
	ui->treeViewSearchResults->setStyleSheet(skinSettings.listViews);
}

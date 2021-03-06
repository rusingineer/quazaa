/*
** $Id$
**
** Copyright © Quazaa Development Team, 2009-2013.
** This file is part of QUAZAA (quazaa.sourceforge.net)
**
** Quazaa is free software; this file may be used under the terms of the GNU
** General Public License version 3.0 or later as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Quazaa is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**
** Please review the following information to ensure the GNU General Public
** License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** You should have received a copy of the GNU General Public License version
** 3.0 along with Quazaa; if not, write to the Free Software Foundation,
** Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "widgetscheduler.h"
#include "ui_widgetscheduler.h"
#include "dialogscheduler.h"

#include "quazaasettings.h"
#include "skinsettings.h"

#include "debug_new.h"

CWidgetScheduler::CWidgetScheduler( QWidget* parent ) :
	QMainWindow( parent ),
	ui( new Ui::CWidgetScheduler )
{
	ui->setupUi( this );
	restoreState( quazaaSettings.WinMain.SchedulerToolbar );
	setSkin();
}

CWidgetScheduler::~CWidgetScheduler()
{
	delete ui;
}

void CWidgetScheduler::changeEvent( QEvent* e )
{
	QMainWindow::changeEvent( e );
	switch ( e->type() )
	{
	case QEvent::LanguageChange:
		ui->retranslateUi( this );
		break;
	default:
		break;
	}
}

void CWidgetScheduler::saveWidget()
{
	quazaaSettings.WinMain.SchedulerToolbar = saveState();
}

void CWidgetScheduler::on_actionAddScheduledTask_triggered()
{
	CDialogScheduler* dlgScheduler = new CDialogScheduler( this );
	dlgScheduler->show();
}

void CWidgetScheduler::on_actionScheduleProperties_triggered()
{
	CDialogScheduler* dlgScheduler = new CDialogScheduler( this );
	dlgScheduler->show();
}

void CWidgetScheduler::setSkin()
{

}

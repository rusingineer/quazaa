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

#include "widgethome.h"
#include "ui_widgethome.h"
#include "dialogadddownload.h"
#include "dialogopentorrent.h"
#include "dialogsettings.h"
#include "wizardquickstart.h"
#include "widgetsearchtemplate.h"
#include "systemlog.h"

#include "quazaasettings.h"
#include "skinsettings.h"

#ifdef _DEBUG
#include "debug_new.h"
#endif

#include <QDesktopServices>
#include <QUrl>

WidgetHome::WidgetHome(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::WidgetHome)
{
	ui->setupUi(this);
    ui->comboBoxHomeFileType->setView(new QListView());
    connect(ui->labelWelcomeSecurityLink, SIGNAL(linkActivated(QString)), this, SIGNAL(triggerSecurity()));
    ui->lineEditWelcomeSearch->setText(quazaaSettings.WinMain.HomeSearchString);
	setSkin();
}

WidgetHome::~WidgetHome()
{
	delete ui;
}

void WidgetHome::changeEvent(QEvent* e)
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

void WidgetHome::on_labelLibraryTaskHashFaster_linkActivated(QString link)
{
	Q_UNUSED(link);
}

void WidgetHome::on_labelTorrentsTaskSeedTorrentLink_linkActivated(QString link)
{
	Q_UNUSED(link);
}

void WidgetHome::on_labelWelcomeURLDownloadLink_linkActivated(QString link)
{
	Q_UNUSED(link);
	DialogAddDownload* dlgAddDownload = new DialogAddDownload(this);
	dlgAddDownload->show();
}

void WidgetHome::on_labelWelcomeOpenTorrentLink_linkActivated(QString link)
{
	Q_UNUSED(link);
	DialogOpenTorrent* dlgOpenTorrent = new DialogOpenTorrent(this);
	dlgOpenTorrent->show();
}

void WidgetHome::on_labelWelcomeSkinLink_linkActivated(QString link)
{
	Q_UNUSED(link);
	DialogSettings* dlgSettings = new DialogSettings(this, SettingsPage::Skins);
	dlgSettings->show();
}

void WidgetHome::on_labelWelcomeWizardLink_linkActivated(QString link)
{
	Q_UNUSED(link);
	WizardQuickStart* wzrdQuickStart = new WizardQuickStart(this);
	wzrdQuickStart->exec();
}

void WidgetHome::on_labelWelcomeUserGuideLink_linkActivated(QString link)
{
	Q_UNUSED(link);

	QDesktopServices::openUrl(QUrl("https://sourceforge.net/apps/mediawiki/quazaa/index.php?title=Manual", QUrl::TolerantMode));
}

void WidgetHome::saveWidget()
{
    quazaaSettings.WinMain.HomeSearchString = ui->lineEditWelcomeSearch->text();
}

void WidgetHome::on_toolButtonWelcomeSearch_clicked()
{
	QString m_sSearchString = ui->lineEditWelcomeSearch->text();
	emit requestSearch(&m_sSearchString);
}

void WidgetHome::setSkin()
{

}

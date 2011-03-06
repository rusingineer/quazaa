/*
** dialogprivatemessages.h
**
** Copyright © Quazaa Development Team, 2009-2011.
** This file is part of QUAZAA (quazaa.sourceforge.net)
**
** Quazaa is free software; this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
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

#ifndef DIALOGPRIVATEMESSAGES_H
#define DIALOGPRIVATEMESSAGES_H

#include <QDialog>
#include "widgetchatinput.h"
#include "chatsession.h"

class WidgetPrivateMessage;
class QTextDocument;

namespace Ui {
	class DialogPrivateMessages;
}

class DialogPrivateMessages : public QDialog {
	Q_OBJECT
public:
	DialogPrivateMessages(QWidget *parent = 0);
	~DialogPrivateMessages();

	WidgetPrivateMessage* FindByGUID(QUuid oGUID);

	void OpenChat(CChatSession* pSess);

protected:
	void changeEvent(QEvent *e);
	QList<WidgetPrivateMessage*> m_lChatWindows;

private:
	Ui::DialogPrivateMessages *ui;
	WidgetChatInput *widgetChatInput;
	WidgetPrivateMessage* m_pCurrentWidget;

public slots:
	void onMessageSent(QTextDocument* pDoc);
private slots:
	void on_tabWidgetPrivateMessages_tabCloseRequested(int index);
 void on_tabWidgetPrivateMessages_currentChanged(int index);
};

#endif // DIALOGPRIVATEMESSAGES_H

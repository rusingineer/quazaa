/*
** quazaaglobals.h
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

#ifndef QUAZAAGLOBALS_H
#define QUAZAAGLOBALS_H

#include <QString>

#define LOG_QUERY_HANDLING 0
#define LOG_MALFORMATTED_QUERIES 0
#define LOG_ROUTED_PACKETS 0
#define LOG_CONNECTIONS 0

class QuazaaGlobals
{
public:
	static QString APPLICATION_NAME();
	static QString APPLICATION_VERSION();
	static QString APPLICATION_VERSION_STRING();
	static QString APPLICATION_FINGERPRINT();
	static QString APPLICATION_ORGANIZATION_NAME();
	static QString APPLICATION_ORGANIZATION_DOMAIN();
	static QString USER_AGENT_STRING();
	static QString VENDOR_CODE();
	static QString MEDIA_OPEN_FILTER();
	static QString DATA_PATH();
	static QString STORAGE_PATH();
	static QString SETTINGS_PATH();
	static QString INI_FILE();

private:
	static QString HOME_PATH();
};

#endif // QUAZAAGLOBALS_H

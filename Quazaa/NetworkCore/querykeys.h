/*
** querykeys.h
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

#ifndef QUERYKEYS_H
#define QUERYKEYS_H

#include "types.h"

class QHostAddress;

class QueryKeys
{
protected:
	quint32*	m_pTable;
	quint32		m_nTable;
public:
	QueryKeys();
	~QueryKeys();

	void prepare();
	quint32 create( QHostAddress pAddr );
	bool check( QHostAddress pAddr, quint32 nKey );
};

extern QueryKeys queryKeys;

#endif // QUERYKEYS_H

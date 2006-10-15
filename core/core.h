/***************************************************************************
 *   Copyright (C) 2005/06 by The Quassel Team                             *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CORE_H_
#define _CORE_H_

#include <QMap>
#include <QString>
#include <QVariant>

#include "server.h"

typedef QMap<QString, QVariant> VarMap;

class Core : public QThread {
  Q_OBJECT

  public:

    static void init();
    static VarMap loadNetworks();
    static void storeNetworks(VarMap);
    static VarMap loadIdentities();
    static void storeIdentities(VarMap);

  public slots:
    void inputLine(const QString &);   // temp
    void connectToIrc(const QString &, quint16 port = 6667);

  signals:
    void outputLine(const QString &);  // temp
    
  private:
    void run();

    Server server; // temp

};

#endif

/***************************************************************************
 *   Copyright (C) 2008 by I2P-Messenger                                   *
 *   Messenger-Dev@I2P-Messenger                                           *
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
#ifndef FORM_DEBUGMESSAGES_H
#define FORM_DEBUGMESSAGES_H

#include <QtGlobal>
#include <QtGui>

#include "Core.h"
#include "DebugMessageManager.h"
#include "ui_form_DebugMessages.h"

class form_DebugMessages : public QDialog, private Ui::form_DebugMessages {
  Q_OBJECT
public:
  form_DebugMessages(CCore &core, QDialog *parent = 0);
  ~form_DebugMessages();

  // forbid some operators
  form_DebugMessages(const form_DebugMessages &) = delete;
  form_DebugMessages &operator=(const form_DebugMessages &) = delete;

  void getFocus();

private slots:
  void newDebugMessage();
  void clearDebugMessages();
  void connectionDump();

signals:
  void closingDebugWindow();

private:
  CCore &core;
  CDebugMessageManager *DebugMessageManager;

  void closeEvent(QCloseEvent *e);
  void keyPressEvent(QKeyEvent *event);
};
#endif

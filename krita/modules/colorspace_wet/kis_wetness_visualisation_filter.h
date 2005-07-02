/* 
 * kis_wetness_visualisation_filter.h -- Part of Krita
 *
 * Copyright (c) 2004 Boudewijn Rempt (boud@valdyas.org)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _WETNESS_VISUALISATION_FILTER_H
#define _WETNESS_VISUALISATION_FILTER_H

#include <qobject.h>
#include <qtimer.h>
#include <kactionclasses.h>

class KisView;

class WetnessVisualisationFilter : public QObject
{
Q_OBJECT
public:
	WetnessVisualisationFilter(KisView* view);
	virtual ~WetnessVisualisationFilter() {}
	void setAction(KToggleAction* action);
	
private slots:
	void slotActivated();
	void slotTimeout();

private:
	KisView * m_view;
	KToggleAction * m_action;
	QTimer m_timer;
};

#endif // _WETNESS_VISUALISATION_FILTER_H

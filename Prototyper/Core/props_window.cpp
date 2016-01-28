
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2016 Igor Mironchik

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Prototyper include.
#include "props_window.hpp"
#include "props_widget.hpp"
#include "top_gui.hpp"
#include "project_window.hpp"

// Qt include.
#include <QCloseEvent>


namespace Prototyper {

namespace Core {

//
// PropsWindowPrivate
//

class PropsWindowPrivate {
public:
	PropsWindowPrivate( PropsWindow * parent )
		:	q( parent )
		,	m_widget( 0 )
	{
	}

	//! Init.
	void init();

	//! Parent.
	PropsWindow * q;
	//! Central widget.
	PropsWidget * m_widget;
}; // class PropsWindowPrivate

void PropsWindowPrivate::init()
{
	m_widget = new PropsWidget( q );

	q->setCentralWidget( m_widget );

	q->setWindowTitle( PropsWindow::tr( "Properties" ) );
}


//
// PropsWindow
//

PropsWindow::PropsWindow( QWidget * parent, Qt::WindowFlags f )
	:	QMainWindow( parent, f )
	,	d( new PropsWindowPrivate( this ) )
{
	d->init();
}

PropsWindow::~PropsWindow()
{
}

void
PropsWindow::closeEvent( QCloseEvent * e )
{
	e->ignore();

	TopGui::instance()->projectWindow()->hidePropsWindow();
}

} /* namespace Core */

} /* namespace Prototyper */

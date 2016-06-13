
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

#ifndef PROTOTYPER__CORE__FORM_HSLIDER_HPP__INCLUDED
#define PROTOTYPER__CORE__FORM_HSLIDER_HPP__INCLUDED

// Qt include.
#include <QGraphicsItem>
#include <QScopedPointer>

// Prototyper include.
#include "form_object.hpp"
#include "form_resizable.hpp"
#include "project_cfg.hpp"


namespace Prototyper {

namespace Core {

//
// FormHSlider
//

class FormHSliderPrivate;

//! Combobox on the form.
class FormHSlider
	:	public QGraphicsItem
	,	public FormObject
	,	public FormResizable
{
public:
	FormHSlider( const QRectF & rect, Form * form, QGraphicsItem * parent = 0 );
	~FormHSlider();

	//! Post deletion.
	void postDeletion() Q_DECL_OVERRIDE;

	void paint( QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0 ) Q_DECL_OVERRIDE;

	static void draw( QPainter * painter, const QRectF & rect,
		const QPen & pen );

	//! Set pen.
	void setObjectPen( const QPen & p ) Q_DECL_OVERRIDE;

	//! \return Cfg.
	Cfg::HSlider cfg() const;
	//! Set cfg.
	void setCfg( const Cfg::HSlider & c );

	QRectF boundingRect() const Q_DECL_OVERRIDE;

protected:
	//! Resize.
	void resize( const QRectF & rect ) Q_DECL_OVERRIDE;
	//! Move resizable.
	void moveResizable( const QPointF & delta ) Q_DECL_OVERRIDE;

private:
	friend class FormHSliderPrivate;

	Q_DISABLE_COPY( FormHSlider )

	QScopedPointer< FormHSliderPrivate > d;
}; // class FormHSlider

} /* namespace Core */

} /* namespace Prototyper */

#endif // PROTOTYPER__CORE__FORM_HSLIDER_HPP__INCLUDED

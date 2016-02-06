
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
#include "form_object.hpp"


namespace Prototyper {

namespace Core {

//
// FormObject
//

FormObject::FormObject()
	:	m_id( 0 )
{
}

FormObject::~FormObject()
{
}

quint64
FormObject::objectId() const
{
	return m_id;
}

void
FormObject::setObjectId( quint64 i )
{
	m_id = i;
}

const QPen &
FormObject::objectPen() const
{
	return m_pen;
}

void
FormObject::setObjectPen( const QPen & p )
{
	m_pen = p;
}

const QBrush &
FormObject::objectBrush() const
{
	return m_brush;
}

void
FormObject::setObjectBrush( const QBrush & b )
{
	m_brush = b;
}

} /* namespace Core */

} /* namespace Prototyper */
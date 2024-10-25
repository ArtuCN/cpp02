/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:28:34 by aconti            #+#    #+#             */
/*   Updated: 2024/10/25 15:44:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	this->_x = Fixed();
	this->_y = Fixed();
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
	
}

Point& Point::operator=(const Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
	return (*this);
}

Point::Point(const Point &point)
{
	*this = point;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return this->_x.toFloat();
}

Fixed Point::getY() const
{
	return this->_y.toFloat();
}

double makeArea(Point const a, Point const b, Point const c)
{
	double area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())).toFloat() / 2;
	if (area < 0)
		area = -area;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double a1, a2, a3, aTriangle;

	aTriangle = makeArea(a, b, c);
	a1 = makeArea(a, b, point);
	a2 = makeArea(b, c, point);
	a3 = makeArea(c, a, point);
	
	if (a1 + a2 + a3 != aTriangle || a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	return (true);
}
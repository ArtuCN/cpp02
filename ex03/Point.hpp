/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:26:42 by aconti            #+#    #+#             */
/*   Updated: 2024/10/25 14:38:20 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "fixed.hpp"
#include <iostream>


class Point
{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point& operator=(const Point &point);
		Point(const Point &point);		
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
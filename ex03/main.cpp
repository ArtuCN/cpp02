/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:12:32 by aconti            #+#    #+#             */
/*   Updated: 2024/10/25 15:46:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include "Point.hpp"

int main( void )
{
	bool res = bsp(Point(), Point(Fixed(1), Fixed(3)), Point(Fixed(3), Fixed(1)), Point(Fixed(1), Fixed(2)));
	if (res)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return 0;
}
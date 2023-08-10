/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:47:14 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/10 10:48:19 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point(void);
		Point(const Point &copy);
		Point(const float x, const float y);
		~Point();
		Point &operator=(const Point &point);

		Fixed get_X(void) const;
		Fixed get_Y(void) const;
};
std::ostream &operator<<(std::ostream &out, const Point &point);
#endif

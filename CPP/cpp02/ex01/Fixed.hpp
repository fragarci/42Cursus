/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:32:51 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/25 13:22:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed;

class Fixed
{
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floater);
		Fixed(const Fixed &copy);
		virtual ~Fixed();
		Fixed &operator=(const Fixed &op);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int								value;
		const static int	fractional_bits = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

# endif

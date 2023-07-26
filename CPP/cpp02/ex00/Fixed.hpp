/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:32:51 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/25 12:58:53 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed;

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		virtual ~Fixed();
		Fixed &operator=(const Fixed &op);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int								value;
		const static int	fractional_bits = 8;
};

#endif

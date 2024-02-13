/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:32:52 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 10:37:41 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		const int	_nbr;
	public:
		Data(int nbr);
		~Data();
		int	getNbr(void);
};

#endif

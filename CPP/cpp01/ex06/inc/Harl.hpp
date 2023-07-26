/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:05:16 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/24 17:37:51 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>


class Harl
{
	private:
		enum	level { INVALID, DEBUG, INFO, WARNING, ERROR };
		Harl::level	_convert(std::string str_level);
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
#endif

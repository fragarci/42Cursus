/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:54:59 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:20:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"
# include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &o);
		virtual ~AAnimal() = 0;

		AAnimal	&operator=(const AAnimal &o);
		virtual void	makeSound(void) const;
		std::string	getType(void);
};

#endif

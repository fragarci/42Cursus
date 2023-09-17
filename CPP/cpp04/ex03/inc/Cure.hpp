/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:28 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 22:20:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string _type;
	public:
		Cure(void);
		Cure(Cure const & o);
		~Cure();
		std::string const & getType() const;
		Cure *clone() const;
		void use(ICharacter& target);
		Cure & operator=(Cure const & o);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:19:26 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 12:13:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : AMateria
{
	public:
		Cure(void);
		Cure(Cure const & o);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
		AMateria & operator=(AMateria const & o);
};

#endif

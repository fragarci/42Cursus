/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:39:28 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 12:13:33 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : AMateria
{
	public:
		Ice(void);
		Ice(Ice const & o);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
		AMateria & operator=(AMateria const & o);
};

#endif

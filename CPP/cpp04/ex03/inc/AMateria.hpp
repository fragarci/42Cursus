/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:15:33 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 12:13:02 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class AMateria
{
	protected:
	std::string type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & o);

		std::string const & getType(void) const;

		virtual ~AMateria() = 0;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& taget);
		virtual AMateria & operator=(AMateria const & o) = 0;
};

#endif

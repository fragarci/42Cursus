/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:30:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 11:58:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : ICharacter
{
	private:
		std::string _name;
		AMateria	*_inventory[4];
	public:
		Character(void);
		Character(std::string name);
		Character(Character const & o);
		~Character();

		std::string const & getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character & operator=(Character const & o);
};

#endif

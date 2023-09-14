/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:15:39 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:20:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(const Dog &o);
		~Dog();
		Dog &operator=(const Dog &o);
		void makeSound(void);
};

#endif

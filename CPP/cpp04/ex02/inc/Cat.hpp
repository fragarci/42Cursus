/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:01:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:20:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(const Cat &o);
		~Cat();
		Cat &operator=(const Cat &o);
		void	makeSound(void) const;
};

#endif

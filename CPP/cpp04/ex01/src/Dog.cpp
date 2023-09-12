/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:54 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/22 11:51:10 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog") {}

void Dog::makeSound(void) { std::cout << "[ " << this << " ] " << this->_type << ": Awooooooo" << std::endl; }

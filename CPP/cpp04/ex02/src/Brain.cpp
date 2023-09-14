/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:37:19 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:14 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "**INTERNAL SCREAMS**";
	std::cout << "[ " << this << " ] Brain Created" << std::endl;
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "[ " << this << " ] Brain destroyed" << std::endl;
}

Brain::Brain(const Brain &o)
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = o.ideas[i];
}

Brain& Brain::operator=(const Brain &o)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = o.ideas[i];
	return (*this);
}

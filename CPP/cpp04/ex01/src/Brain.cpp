/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:50:25 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/07 13:00:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void) { std::cout << "[ " << this << " ] Brain created" << std::endl; }

Brain::~Brain() { std::cout << "[ " << this << " ] Brain destroyed" << std::endl; }

Brain::Brain(const Brain &o) { *this = o; }

Brain& Brain::operator=(const Brain &o)
{
		return (*this);
}

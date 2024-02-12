/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:27:35 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/23 12:04:18 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("Default Target")
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 145, 137), _target(target)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o): AForm(o), _target(o._target)
{
	if (DEBUG) {std::cout << "Copy Constructor Called" << std::endl;}
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &o)
{
	_target = o._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkPremissons(executor);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("Default Target")
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o): AForm(o), _target(o._target)
{
	if (DEBUG) {std::cout << "Copy Constructor Called" << std::endl;}
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
	_target = o._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
  int  chance;
	checkPremissons(executor);
  srand(time(NULL));
  chance = rand() % 2;
  if (chance)
    std::cout << this->_target << " has been robotomized successfully" << std::endl;
  else
    std::cout << this->_target << " couldnt't be robotomized" << std::endl;
    
  
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:16:16 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/12 12:19:37 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	if (DEBUG) { std::cout << "Default Constructor Called" << std::endl; }
}

Intern::Intern(const Intern &o)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = o;
}

Intern &Intern::operator=(const Intern &o)
{
	if (this == &o)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	if (DEBUG)
		std::cout << "Destructor Called" << std::endl;
}

static AForm *makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string form, std::string target)
{
	AForm *(*forms_ptr[])(const std::string target) = {&makeShrubbery, &makeRobotomy, &makePardon};
	std::string forms_str[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms_str[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return(forms_ptr[i](target));
		}
	}
	std::cout << "Intern couldn't create " << form << std::endl;
	return (NULL);
}

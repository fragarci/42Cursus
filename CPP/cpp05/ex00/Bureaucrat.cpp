/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:07:03 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/11 11:53:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT { return ("Bureaucrat grade is too high"); }
const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT { return ("Bureaucrat grade is too low"); }

Bureaucrat::Bureaucrat(void): _name("Default Bureaucrat Name"), _grade(150)
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

Bureaucrat::Bureaucrat(std::string name, uint8_t grade): _name(name)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &o)
{
	_name = o._name;
	_grade = o._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

std::string	Bureaucrat::getName(void) const { return (_name); }
uint8_t	Bureaucrat::getGrade(void) const { return (_grade); }

void	Bureaucrat::incGrade(void) {
	if ((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decGrade(void) {
	if ((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &o)
{
	out << o.getName() << ", bureaucrat grade " << unsigned(o.getGrade());
	return (out);
}

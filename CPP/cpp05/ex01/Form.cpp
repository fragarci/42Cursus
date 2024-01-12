/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:12:43 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/12 19:51:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

#if defined(__APPLE__) && defined(__MACH__)
const char *Form::GradeTooHighException::what() const _NOEXCEPT { return ("Form grade is too high"); }
const char *Form::GradeTooLowException::what() const _NOEXCEPT { return ("Form grade is too low"); }
#endif
#if defined(__linux__)
const char *Form::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Form grade is too high"); }
const char *Form::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Form grade is too low"); }
#endif

Form::Form(void): _name("Default Form"), _formSigned(false), _gradeSign(150), _gradeExecute(150)
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

Form::Form(std::string name, uint8_t gradeSign, uint8_t gradeExecute): _name(name), _formSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &o)
{
	_formSigned = o._formSigned;
	return (*this);
}

Form::~Form() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

std::string	Form::getName(void) const { return (_name); }
bool		Form::isSigned(void) const { return (_formSigned); }
uint8_t		Form::getSignGrade(void) const { return (_gradeSign); }
uint8_t		Form::getExecuteGrade(void) const { return (_gradeExecute); }

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_formSigned = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &o)
{
	out << o.getName() << ", form sign grade: " << unsigned(o.getSignGrade())
		<< ", form execute grade: " << unsigned(o.getExecuteGrade()) << " Signed: "
		<< std::boolalpha << o.isSigned();
	return (out);
}

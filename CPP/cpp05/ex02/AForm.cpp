/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:12:43 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/23 11:04:03 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

#if defined(__APPLE__) && defined(__MACH__)
const char *AForm::GradeTooHighException::what() const _NOEXCEPT { return ("Form grade is too high"); }
const char *AForm::GradeTooLowException::what() const _NOEXCEPT { return ("Form grade is too low"); }
#endif
#if defined(__linux__)
const char *AForm::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Form grade is too high"); }
const char *AForm::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Form grade is too low"); }
#endif

AForm::AForm(void): _name("Default Form"), _formSigned(false), _gradeSign(150), _gradeExecute(150)
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

AForm::AForm(std::string name, uint8_t gradeSign, uint8_t gradeExecute): _name(name), _formSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
	if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &o): _name(o._name), _formSigned(o._formSigned), _gradeSign(o._gradeSign), _gradeExecute(o._gradeExecute)
{
	if (DEBUG) {std::cout << "Copy Constructor Called" << std::endl;}
}

AForm &AForm::operator=(const AForm &o)
{
	_formSigned = o._formSigned;
	return (*this);
}

AForm::~AForm() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

std::string	AForm::getName(void) const { return (_name); }
bool		AForm::isSigned(void) const { return (_formSigned); }
uint8_t		AForm::getSignGrade(void) const { return (_gradeSign); }
uint8_t		AForm::getExecuteGrade(void) const { return (_gradeExecute); }

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_formSigned = true;
}

void AForm::checkPremissons(const Bureaucrat &b)
{
	uint8_t	grade = b.getGrade();

	if (grade > _gradeExecute || !isSigned())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const AForm &o)
{
	out << o.getName() << ", form sign grade: " << unsigned(o.getSignGrade())
		<< ", form execute grade: " << unsigned(o.getExecuteGrade()) << " Signed: "
		<< std::boolalpha << o.isSigned();
	return (out);
}

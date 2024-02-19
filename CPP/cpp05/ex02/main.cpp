/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/19 16:17:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#if defined(__APPLE__) && defined(__MACH__)
void	ft_leaks(void)
{
	system("leaks -q ex02");
}
#endif

int	main(void)
{
	#if defined(__APPLE__) && defined(__MACH__)
	atexit(ft_leaks);
	#endif
	Bureaucrat b1("W_bureaucrat", 1);
	Bureaucrat b2("L_bureaucrat", 150);
  ShrubberyCreationForm shrubbery("shrubbery");
	RobotomyRequestForm robotomy("robotomy");
  PresidentialPardonForm pardon("pardon");
  std::cout << "This should fail" << std::endl;
  b2.signForm(shrubbery);
  b2.signForm(robotomy);
  b2.signForm(pardon);
  b2.executeForm(shrubbery);
  b2.executeForm(robotomy);
  b2.executeForm(pardon);
  std::cout << "This souldn't fail" << std::endl;
	b1.signForm(shrubbery);
  b1.signForm(robotomy);
  b1.signForm(pardon);
	b1.executeForm(shrubbery);
  b1.executeForm(robotomy);
  b1.executeForm(pardon);
	return (EXIT_SUCCESS);
}

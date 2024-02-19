/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/19 16:19:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#if defined(__APPLE__) && defined(__MACH__)
void	ft_leaks(void)
{
	system("leaks -q ex03");
}
#endif

int	main(void)
{
	#if defined(__APPLE__) && defined(__MACH__)
	atexit(ft_leaks);
	#endif
  Intern intern;
  AForm *shruberry;
  AForm *robotomy;
  AForm *pardon;
  AForm *bad;
  (void) shruberry;
  (void) robotomy;
  (void) pardon;
  (void) bad;
  shruberry = intern.makeForm("ShrubberyCreationForm", "shruberry");
  robotomy = intern.makeForm("RobotomyRequestForm", "robotomy");
  pardon = intern.makeForm("PresidentialPardonForm", "pardon");
  bad = intern.makeForm("NonExistentForm", "bad");
  delete shruberry;
  delete robotomy;
  delete pardon;
	return (EXIT_SUCCESS);
}

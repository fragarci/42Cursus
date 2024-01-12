/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/12 19:50:38 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#if defined(__APPLE__) && defined(__MACH__)
void	ft_leaks(void)
{
	system("leaks -q ex00");
}
#endif

int	main(void)
{
	Bureaucrat wBureaucrat = Bureaucrat("W Bureaucrat", 1);
	Bureaucrat lBureaucrat = Bureaucrat("L Bureaucrat", 150);

	Form	goodForm = Form("Good Form", 1, 1);
	Form	*formTooHigh;
	Form	*formTooLow;

	(void) formTooHigh;
	(void) formTooLow;

	#if defined(__APPLE__) && defined(__MACH__)
	atexit(ft_leaks);
	#endif

	try { formTooHigh = new Form("formTooHigh", 0, 0); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try { formTooLow = new Form("formTooLow", 151, 151); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	std::cout << goodForm << std::endl;

	lBureaucrat.signForm(goodForm);
	wBureaucrat.signForm(goodForm);
	wBureaucrat.signForm(goodForm);

	std::cout << goodForm << std::endl;

	return (EXIT_SUCCESS);
}

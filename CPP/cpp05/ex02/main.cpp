/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/23 12:01:58 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#if defined(__APPLE__) && defined(__MACH__)
void	ft_leaks(void)
{
	system("leaks -q ex00");
}
#endif

int	main(void)
{
	#if defined(__APPLE__) && defined(__MACH__)
	atexit(ft_leaks);
	#endif
	Bureaucrat me("Cixfra", 1);
	ShrubberyCreationForm form("garden");
	me.signForm(form);
	form.execute(me);
	return (EXIT_SUCCESS);
}

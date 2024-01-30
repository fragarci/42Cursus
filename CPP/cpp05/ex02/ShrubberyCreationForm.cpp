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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Default Target")
{
	if (DEBUG) {std::cout << "Default Constructor Called" << std::endl;}
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (DEBUG) {std::cout << "Parameter Constructor Called" << std::endl;}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o): AForm(o), _target(o._target)
{
	if (DEBUG) {std::cout << "Copy Constructor Called" << std::endl;}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
	_target = o._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { if (DEBUG) {std::cout << "Destructor Called" << std::endl;} }

void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	checkPremissons(executor);
	std::ofstream outfile (_target + "_shrubbery");
	outfile	<< "           {{ }{" << "\n"
			<< "          {{}}}{{" << "\n"
			<< "        {{}}{}}" << "\n"
			<< "           }}}}{" << "\n"
			<< "          {{}}}" << "\n"
			<< "         }{{}{}}" << "\n"
			<< "           {{}{}}" << "\n"
			<< "         }}{{}}" << "\n"
			<< "          {{}}{{" << "\n"
			<< "           \\  /" << "\n"
			<< "        .-''| |``-." << "\n"
			<< "       '-._/_o_\\_.-'" << "\n"
			<< "        `._     _.'" << "\n"
			<< "         | :F_P: |" << "\n"
			<< "         `._    .'" << "\n"
			<<	"            `--'" << std::endl;
	outfile.close();
	std::cout << "Creating ASCII trees :3" << std::endl;
}

/*
           {{ }{
          {{}}}{{
        {{}}{}}
           }}}}{
          {{}}}
         }{{}{}}
           {{}{}}
         }}{{}}
          {{}}{{
           \  /
        .-''| |``-.
       '-._/_o_\_.-'
        `._     _.'
         | :F_P: |
         `._    .'
            `--'
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:55 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/11 10:56:10 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include <cstdint>

# define DEBUG 0

class Bureaucrat
{
	private:
		std::string	_name;
		uint8_t		_grade;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const _NOEXCEPT;
		};
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, uint8_t grade);
		Bureaucrat(const Bureaucrat &o);
		Bureaucrat &operator=(const Bureaucrat &o);
		~Bureaucrat();
		std::string	getName(void) const;
		uint8_t		getGrade(void) const;
		void		incGrade(void);
		void		decGrade(void);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &o);
#endif

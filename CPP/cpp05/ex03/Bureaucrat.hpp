/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:55 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/23 11:08:29 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

#if defined(__APPLE__) && defined(__MACH__)
# include <cstdint>
#endif

#if defined(__linux__)
# include <stdint.h>
#endif
# define DEBUG 0

class AForm;
class Bureaucrat
{
	private:
		std::string	_name;
		uint8_t		_grade;
		class GradeTooHighException : public std::exception
		{
			public:
				#if defined(__APPLE__) && defined(__MACH__)
				const char *what() const _NOEXCEPT;
				#endif
				#if defined(__linux__)
				const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				#endif
		};
		class GradeTooLowException : public std::exception
		{
			public:
				#if defined(__APPLE__) && defined(__MACH__)
				const char *what() const _NOEXCEPT;
				#endif
				#if defined(__linux__)
				const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				#endif
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
		void		signForm(AForm &form);
    void    executeForm(AForm const &form) const;
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &o);
#endif

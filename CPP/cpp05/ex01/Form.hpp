/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:55 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/12 19:32:37 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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

class Bureaucrat;
class Form
{
	private:
		std::string const	_name;
		bool				_formSigned;
		uint8_t const		_gradeSign;
		uint8_t const		_gradeExecute;
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
		Form(void);
		Form(std::string name, uint8_t gradeSign, uint8_t gradeExecute);
		Form(const Form &o);
		Form &operator=(const Form &o);
		~Form();
		std::string	getName(void) const;
		bool		isSigned(void) const;
		uint8_t		getSignGrade(void) const;
		uint8_t		getExecuteGrade(void) const;
		void		beSigned(const Bureaucrat &bureaucrat);

};
std::ostream &operator<<(std::ostream &out, const Form &o);
#endif

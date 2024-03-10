/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:34:43 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 12:13:49 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;
		int	_topAndRemove(void);
	public:
		RPN (void);
		RPN (const RPN &o);
		~RPN (void);
		RPN &operator=(const RPN &o);
		void	calculate(const std::string &str);
};

#endif

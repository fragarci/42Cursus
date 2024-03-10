/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:39:57 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 12:27:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) { return ; }
RPN::RPN(const RPN &o) { *this = o; }
RPN::~RPN(void) { return ; }

RPN &RPN::operator=(const RPN &o)
{
	if (this != &o)
		this->_stack = o._stack;
	return (*this);
}

int	RPN::_topAndRemove()
{
	int ret = this->_stack.top();
	this->_stack.pop();
	return (ret);
}

void	RPN::calculate(const std::string &str)
{
	int	op1;
	int	op2;

	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isspace(str[i]))
			continue;
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (std::cerr << "Error" << std::endl, (void)0);
		if (str[i] >= '0' && str[i] <= '9')
			this->_stack.push((int)str[i] - '0');
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (this->_stack.size() != 2)
				return (std::cerr << "Error" << std::endl, (void)0);
			op2 = _topAndRemove();
			op1 = _topAndRemove();
			if (str[i] == '+')
				this->_stack.push(op1 + op2);
			else if (str[i] == '-')
				this->_stack.push(op1 - op2);
			else if (str[i] == '*')
				this->_stack.push(op1 * op2);
			else if (str[i] == '/')
				this->_stack.push(op1 / op2);
		}
	}
	std::cout << _topAndRemove() << std::endl;
}

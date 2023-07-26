/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:21:42 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/24 13:27:29 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;

Account::Account(int deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << \
	"index:" << this->_accountIndex << \
	";amount:" << this->checkAmount() << \
	";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << \
	"index:" << this->_accountIndex << \
	";amount:" << this->checkAmount() << \
	";closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t current_time;

	current_time = time(NULL);
	std::cout << std::put_time(localtime(&current_time), "[%Y%m%d_%H%M%S] ");
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << \
	"accounts:" << Account::getNbAccounts() << \
	";total:" << Account::getTotalAmount() << \
	";deposits:" << Account::getNbDeposits() << \
	";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << \
	"index:" << this->_accountIndex << \
	";deposits:" << this->_nbDeposits << \
	";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << \
	"index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << \
	";deposit:" << deposit << \
	";amount:" << this->checkAmount() + deposit << \
	";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << \
	"index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << \
	";amount:" << this->checkAmount() - withdrawal << \
	";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}

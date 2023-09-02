/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:17:12 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/02 01:17:13 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit)
{

	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	checkAmount();
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	checkAmount();
	std::cout << "closed" << std::endl;
}

Account::Account(){}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts<< ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";";
	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout
	<< "deposit:" << deposit << ";"
	<< "amount:" << _amount << ";"
	<< "nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout
	<< "withdrawal:" << withdrawal << ";"
	<< "amount:" << _amount << ";"
	<< "nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";";
	return _amount;
}

void	Account::displayStatus(void) const
{
	checkAmount();
	std::cout
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	char		buffer[20];

	time = std::time(NULL);
	std::strftime(
				buffer,
				sizeof(buffer),
			 	"[%Y%m%d_%H%M%S]",
				std::localtime(&time)
				);
	std::cout << buffer << " ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

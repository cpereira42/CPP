/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:24:13 by cpereira          #+#    #+#             */
/*   Updated: 2021/09/11 16:41:48 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>
#include <string> // To use string
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:\033[1;34m" << _accountIndex ;
	std::cout << "\033[0;37m;amount:\033[1;34m" << initial_deposit ;
	std::cout <<"\033[0;37m;created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "\033[0;37mindex:\033[1;34m" << _accountIndex;
	std::cout << "\033[0;37m;amount:\033[1;34m" << _amount;
	std::cout << "\033[0;37m;closed:" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:\033[1;34m" << getNbAccounts();
	std::cout << "\033[0;37m;total:\033[1;34m" << getTotalAmount();
	std::cout << "\033[0;37m;deposits:\033[1;34m" << _totalNbDeposits;
	std::cout << "\033[0;37m;withdrawals:\033[1;34m" << _totalNbWithdrawals;
	std::cout << "\033[0;37m" << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:\033[1;34m" << _accountIndex ;
	std::cout <<"\033[0;37m;amount:\033[1;34m" << checkAmount();
	std::cout << "\033[0;37m;deposits:\033[1;34m" << _nbDeposits;
	std::cout << "\033[0;37m;withdrawals:\033[1;34m" << _nbWithdrawals;
	std::cout <<"\033[0;37m" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:\033[1;34m" << _accountIndex ;
	std::cout <<"\033[0;37m;p_amount:\033[1;34m" << _amount;
	std::cout << "\033[0;37m;deposits:\033[1;34m" << deposit;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout <<"\033[0;37m;amount:\033[1;34m" << _amount;
	std::cout <<"\033[0;37m;nb_deposits:\033[1;34m" << _nbDeposits;
	std::cout << "\033[0;37m" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:\033[1;34m" << _accountIndex;
	std::cout <<"\033[0;37m;p_amount:\033[1;34m" << _amount;
	std::cout << "\033[0;37m;withdrawals:" ;
	if (_amount < withdrawal)
	{
		std::cout << "\033[1;31mrefused\033[0;37m" << std::endl ;
		return 0;
	}
	_totalNbWithdrawals ++;
	_nbWithdrawals ++;
	std::cout << "\033[1;34m"<< withdrawal;
	_amount -= withdrawal;
	std::cout <<"\033[0;37m;amount:\033[1;34m" << _amount;
	std::cout <<"\033[0;37m;nb_withdrawals:\033[1;34m" << _nbWithdrawals;
	std::cout << "\033[0;37m" << std::endl;
	_totalAmount-=withdrawal;
	return 1;
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);

	tm *ltm = localtime(&now);
	std::cout << '[' << 1900 + ltm->tm_year << 1 + ltm->tm_mon << ltm->tm_mday;
	std::cout << '_' << 5+ltm->tm_hour << 30+ltm->tm_min << ltm->tm_sec << "] ";
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}


int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

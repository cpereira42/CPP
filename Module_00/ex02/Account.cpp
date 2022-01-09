/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:24:13 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/08 21:46:16 by cpereira         ###   ########.fr       */
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
	std::cout << "index:" << _accountIndex ;
	std::cout << ";amount:" << initial_deposit ;
	std::cout <<";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << "" << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex ;
	std::cout <<";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout <<"" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex ;
	std::cout <<";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout <<";amount:" << _amount;
	std::cout <<";nb_deposits:" << _nbDeposits;
	std::cout << "" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout <<";p_amount:" << _amount;
	std::cout << ";withdrawal:" ;
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl ;
		return 0;
	}
	_totalNbWithdrawals ++;
	_nbWithdrawals ++;
	std::cout << ""<< withdrawal;
	_amount -= withdrawal;
	std::cout <<";amount:" << _amount;
	std::cout <<";nb_withdrawals:" << _nbWithdrawals;
	std::cout << "" << std::endl;
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

		
	
	std::cout 
		<< '[' << 1900 + ltm->tm_year << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon 
		<< std::setfill('0') << std::setw(2) << ltm->tm_mday << '_' << ltm->tm_hour 
		<< ltm->tm_min << ltm->tm_sec << "] ";
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

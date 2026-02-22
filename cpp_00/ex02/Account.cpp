#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }


/**
 * @remarks
 * 	std::time → 
 * 	std::tm → a struct with the parts of the time split
 * 	std::strftime → string format time
 */
void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *t = std::localtime(&now);
	char buf[16];

	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", t);
	std::cout << "[" << buf << "] ";
}

/**
 * @brief constructor
 */
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

/**
 * @brief destructor 
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

Account::Account(void)
	: _accountIndex(_nbAccounts), _amount(0),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
}

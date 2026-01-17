#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";created\n";
}

void    Account::makeDeposit(int deposit)
{
    int p_amount = _amount;

    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:"
        << p_amount << ";deposit:" << deposit << ";amount:"
        << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;

    Account::_displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:"
            << p_amount << ";withdrawal:refused\n";
        return (false);
    } else {
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:"
        << p_amount << ";withdrawal:" << withdrawal << ";amount:"
        << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    }
    return (true);
}

int		Account::checkAmount( void ) const {
    return (_amount);
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";deposits:" << _nbDeposits << ";withdrawals:"
        << _nbWithdrawals << "\n";
}

Account::~Account( void ) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";closed\n";
}

void Account::_displayTimestamp(void) {
    time_t timestamp = time(NULL);
    struct tm *t = localtime(&timestamp);

    std::cout << "[" << (t->tm_year + 1900);
    
    if (t->tm_mon + 1 < 10) std::cout << "0";
    std::cout << t->tm_mon + 1;
    
    if (t->tm_mday < 10) std::cout << "0";
    std::cout << t->tm_mday << "_";

    if (t->tm_hour < 10) std::cout << "0";
    std::cout << t->tm_hour;

    if (t->tm_min < 10) std::cout << "0";
    std::cout << t->tm_min;

    if (t->tm_sec < 10) std::cout << "0";
    std::cout << t->tm_sec << "] ";
}

int	Account::getNbAccounts( void ) {
    return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:"
        << _totalAmount << ";deposits:" << _totalNbDeposits
        << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

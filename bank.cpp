#include<iostream>
#include<iomanip>
#include<ctime>
#include<exception>
#include"classes.hpp"


void BANK_ID::chang_money(int new_money)
{
    money = money + new_money;
}
unsigned int BANK_ID::return_money()
{
    return money;
}
void BANK_ID::chang_broken()
{
    broken = true;
}

bool BANK_ID::return_broken()
{
    return broken;
}

void BANK_ID::chang_loan(int new_loan)
{
    loan = loan + new_loan;
}
unsigned long int BANK_ID::return_loan()
{
    return loan;
}
void BANK_ID::print_information()
{
    cout << "number of users : " << user_num << endl;
    cout << "money of bank : " << money << endl;
    cout << "amount of money of loans : " << loan << endl;
    if (broken == false)
    {
        cout << "broke situation : not broken" << endl;
    }
    else
    {
        cout << "broke situation : broken" << endl;
    }
    
}
#include<iostream>
#include<iomanip>
#include<ctime>
#include<new>
#include<exception>
#include"classes.hpp"

string USER_ID::get_username()
{
	string name;
	
	cout << "please enter username : " ;
	getline(cin , name);

	return name;
}

void USER_ID::set_username(string name)
{
	if(isdigit(name[0]) == isdigit('1') )
	{
		throw(invalid_argument("begining of name cant be a number!!!") );
	} 

	int i = 0;
	for( ; i < name.length() ; i++)
	{
		if(isalnum(name[i]) != isalnum('a') )
		{
			throw(invalid_argument("a username has to be contain by alphabets and numbers!!!!"));
		}
	}

	username = name;
	cout << "username : " << username << endl;	
}

string USER_ID::return_username()
{
	return username;
}

void USER_ID::set_date( tm * date )
{

	new_time(date);

	eftetah.day = date->tm_mday;
	eftetah.month = 1 + date->tm_mon;
	eftetah.year = 1900 + date->tm_year;


	engheza.day = date->tm_mday;
	engheza.month = 1 + date->tm_mon;
	engheza.year = 1900 + 2 + date->tm_year;


}

string USER_ID::get_cart_number()
{
	int random;
	string number;
	srand(time(NULL));
	random = rand() % 9000 + 1000;
	number = to_string(random);

	return number;
}

void USER_ID::set_cart_number(string number)
{
	cart_number = number;

	cout << "cart number : " << cart_number << endl;
}


string USER_ID::return_cart()
{
	return cart_number;
}


string USER_ID::get_ip()
{
	string ip_address;

	cout << "Enter the ip : ";
	cin >> ip_address;

	return ip_address;
}

void USER_ID::set_ip(string ip_address)
{	

	ip_list = add_ip(ip_list , ip_num);

	ip_list[ip_num] = ip_address;
	ip_num++;

	
	cout << "ip[" << ip_num << "]is : " << ip_list[ip_num-1] << endl;
}

int USER_ID::return_ip_number()
{
	return ip_num;
}

string USER_ID::return_ip(int number)
{
	return ip_list[number];
	
}

int USER_ID::return_money()
{
    return money;
}

void USER_ID::change_money(int new_money)
{
    money = money + new_money;
}

void USER_ID::change_loan_date(int day)
{
    loan_date = loan_date + day;
}
unsigned int USER_ID::return_loan_date()
{
    return loan_date;
}
void USER_ID::chang_loan(int loan_money)
{
    loan = loan + loan_money;
}
int USER_ID::return_loan()
{
    return loan;
}
void USER_ID::change_profit_date(int day)
{
    profit_date = profit_date + day;
}
unsigned int USER_ID::return_profit_date()
{
    return profit_date;
}

void USER_ID::print_information()
{
	cout << "username : " << username << endl;

	for (size_t i = 0; i < ip_num; i++)
	{
		cout << "ip[" << i << "] : " << ip_list[i] << endl;
	}

	cout << "cart number : " << cart_number << endl;

	cout << "money in account : " << money << endl;

	cout << "days past from payed your last loan : " << loan_date << endl;

	cout << "amount of money you get for loan : " << loan << endl;

	cout << "days passed from you get profits : " << profit_date << endl;

	cout << "date of create cart : " << eftetah.day << "/" << eftetah.month << "/" << eftetah.year << endl;

	cout << "date of expiration of cart : " << engheza.day << "/" << engheza.month << "/" << engheza.year << endl;
}
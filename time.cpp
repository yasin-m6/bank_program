#include<iostream>
#include<iomanip>
#include<ctime>
#include<new>
#include<exception>
#include"classes.hpp"

void new_time(tm * date)
{
	time_t now = time(0);

	date = gmtime(&now);
}

bool check_cart_date(tm * engheza)
{
	tm * today;

	new_time(today);

	if (today->tm_year > engheza->tm_year)
	{
		return false;
	}
	else if(today->tm_year < engheza->tm_year )
	{
		return true;
	}
	else if(today->tm_year == engheza->tm_year)
	{
		if (today->tm_mon +1 > engheza->tm_mon +1)
		{
			return false;
		}
		else if(today->tm_mon + 1 < engheza->tm_mon + 1)
		{
			return true;
		}
		else if(today->tm_mon == engheza->tm_mon)
		{
			if (today->tm_mday > engheza->tm_mday)
			{
				return false;
			}
			else if(today->tm_mday <= engheza->tm_mday)
			{
				cout << "your cart expiration date is near!!!";
				return true;
			}
		}
	}
	return true;
}


int passed_days(time_t * last_date)
{
	time_t new_day;
	double diffrent;
	int day;
	int passed_hours;
	
	new_day = time(0);
	diffrent = difftime(new_day , *last_date);

	day = static_cast<int>(diffrent) / 86400;
	passed_hours = static_cast<int>(diffrent) % 86400;

	*last_date = new_day - passed_hours;
	return day;
}
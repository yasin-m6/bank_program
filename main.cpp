#include<iostream>
#include<new>
#include<exception>
#include<ctime>
#include"classes.hpp"


int main()
{
	USER_ID * user = new(nothrow) USER_ID[1];
	BANK_ID bank;
	time_t now = time(0);
	string command;
	int user_num = 0;
	int day;
	bool another;

	
	
	while(1)
	{
		
		day = passed_days(&now);
		if (day > 0)
		{
			for (size_t i = 0; i < user_num; i++)
			{
				user[i].change_loan_date(day);
				user[i].change_profit_date(day);
			}	
		}

		cout << "*****menu******" << endl;
		cout << "create" << endl;
		cout << "new_ip" << endl;
		cout << "renewal" << endl;
		cout << "transfer" << endl;
		cout << "diposit" << endl;
		cout << "withdraw" << endl;
		cout << "add_profits" << endl;
		cout << "get_loan" << endl;
		cout << "pay_loan" << endl;
		cout << "IP or cart number or username" << endl;
		cout << "bank" << endl;
		


		cout << "Enter your command : " ;
		getline(cin,command);

		if( command.find("create") == 0)
		{
			if (bank.return_broken() == false)
			{
				try
				{
					user = create_newuser(user , command , &user_num);
					cout << "its ok" << endl;
					user_num++;
				}
				catch(bad_alloc & e)
				{
					cerr << "Error , " << e.what() << endl;
				}
			}
			else
			{
				cout << "you cant create new account!" << endl;
				cerr << "The bank is broken!!!" << endl;
			}
			
			
			continue;
		}
		else if( command.find("new_ip") == 0 )
		{
			another = new_ip(user , command , user_num , 7);
			if(another == true)
			{
				another = new_ip(user , command , user_num , command.find("another") +  8);
			}

			continue;
		}
		else if ( command.find("renewal") == 0 )
		{
			renewal(user , command , user_num);
			continue;
		}

		else if( command.find("transfer") == 0 )
		{
			if (bank.return_broken() == false)
			{
				transfer(user , command , user_num);
			}
			else
			{
				cout << "you cant transfer money !" << endl;
				cerr << "The bank is broken!!!" << endl;
			}
			continue;
		}
		else if(command.find("diposit") == 0 || command.find("withdraw") == 0)
		{
			if (bank.return_broken() == false)
			{
				diposit_withdraw(user , &bank , command , user_num);
			}
			else
			{
				cout << "you cant diposit or withdraw money!" << endl;
				cerr << "The bank is broken!!!" << endl;
			}
			continue;
		}
		else if(command.find("add_profits") == 0)
		{
			//profits(user , command , user_num , )
		}
		else if(command.find("get_loan") == 0)
		{
			if (bank.return_broken() == false)
			{
				loan(user , &bank , user_num , command);
			}
			else
			{
				cout << "you cant get loan!" << endl;
				cerr << "The bank is broken!!!" << endl;
			}
			continue;
		}
		else if(command.find("pay_loan") == 0)
		{
			pay_loan(user , &bank , user_num , command);

			continue;
		}
		else if( command.find("exit") == 0)
		{
			cout << "Exit" << endl;
			return 0;
		}

		
		cout << "invalid command!!!" << endl;
		
	}
}
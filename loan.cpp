#include<iostream>
#include<iomanip>
#include<ctime>
#include<exception>
#include"classes.hpp"


void profits(USER_ID * user , string command , int user_num , int * money)
{
    tm * date;
    tm * loan_date;
    string username;
    int sum = 0; 
    int avg = 0;
    int profit = 0;
    int pos = 12;
    int number = -1;
    int i = 0;


    if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
    {
        username = get_str(command , ':' , &pos);
    }
    else
    {
        pos = 0;
    }

    while (number == -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter your username -> ";
            cin >> username;
        }
        
        try
        {
            number = chek_username(user , username , user_num);     
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }
        
        i++;
    }


    if(user[number].return_loan() == 0)
    {
        if (user[number].return_loan_date() > 30)
        {
            if (user[number].return_profit_date() > 30)
            {
                for (size_t j = 0; j < 7 && money[j] > -1; j++)
                {
                    sum = sum + money[j];
                }

                avg = sum / 7;

                profit = avg / 10;

                user[number].change_money( profit );
                user[number].change_profit_date(-1 * user[number].return_profit_date());
            }
            else
            {
                cerr << "Error!! , " << user[number].return_profit_date() << " ago you get your profit" << endl;
                cout << "after " << 30 - user[number].return_profit_date() << " days you can get your profit" << endl;
            }  
        }
        else
        {
            cerr << "Error!! , " << user[number].return_loan_date() << " ago you repayed your loan" << endl;
            cout << "after " << 30 - user[number].return_loan_date() << " days you can get your profit" << endl;
        }
        
    }
    else
    {
        cerr << "you have to repayed your loan first" << endl;
    }

    
    
}


void loan(USER_ID * user , BANK_ID * bank , int user_num , string command)
{
    tm * today;
    string username;
    string ip;
    string money;
    double credit;
    int money2;
    int sum = 0; 
    int profit = 0;
    int pos = 12;
    int number = -1;
    int i = 0;
    bool exist = false;
    char confirmation;

    new_time(today);

    if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
    {
        username = get_str(command , ':' , &pos);
    }
    else
    {
        pos = 0;
    }

    while (number == -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter your username -> ";
            cin >> username;
        }
        
        try
        {
            number = chek_username(user , username , user_num);     
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }
        
        i++;
    }

    i = 0;

    if (pos != 0)
    {
        if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
        {
            ip = get_str(command , ':' , &pos);
        }
        else
        {
            pos = 0;
        }
        
    }
    
    while (exist == false)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter your ip -> ";
            cin >> ip;
        }
        
        try
        {
            exist = chek_correct_ip(ip);
            if (exist == true)
            {
                exist = chek_ip(user , username , user_num);  
            }
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }

        i++;
        
    }

    i = 0;

    if (pos != 0)
    {
        if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
        {
            money = get_str(command , ' ' , &pos);
        }
        else
        {
            pos = 0;
        }
        
    }

    while (money2 <= -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter how much money do you want to get -> ";
            cin >> money2;
        }
        
        money2 = chek_money(money); 
        
        i++;
    }

    if (check_cart_date(today) == false)
	{
	
		cout << "do you want to renewal your cart? " << endl << "Y/N" << endl;
		confirmation = getchar();

		if (confirmation == 'Y')
		{
			renewal(user , command , user_num);
		}
			else
		{
		    if (confirmation != 'N')
			{
				cerr << "invalid command" << endl;
			}
			return;
		}
			
	}

    profit = money2 * 15/100;


    if ( user[number].return_money() >= 3/4 * money2 )
    {
        if(bank->return_money() > money2)
        {
            user[number].chang_loan(money2 + profit);
            bank->chang_money(-1 * money2); //pool be soorat naghdi pardakht shode
            bank->chang_loan(money2);
            cout << "the loan is payed" << endl;
        }
        else
        {
            cerr << "condition of bank is not good!!!" << endl;
        }
    }
    else
    {
        cerr << "you have to have 3/4 loan in your account!!!" << endl;
    }
    
}

void pay_loan(USER_ID * user , BANK_ID * bank , int user_num , string command)
{

    string username;
    string money;
    int money2;
    int loan;
    int pos = 9;
    int number = -1;
    int i = 0;

    if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
    {
        username = get_str(command , ':' , &pos);
    }
    else
    {
        pos = 0;
    }

    while (number == -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter your username -> ";
            cin >> username;
        }
        
        try
        {
            number = chek_username(user , username , user_num);     
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }
        
        i++;
    }

    i = 0;

    if (pos != 0)
    {
        if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
        {
            money = get_str(command , ' ' , &pos);
        }
        else
        {
            pos = 0;
        }
        
    }

    while (money2 <= -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter how much money do you want to transfer -> ";
            cin >> money2;
        }
        
        money2 = chek_money(money); 
        
        i++;
    }

    loan = user[number].return_loan();

    bank->chang_money(money2);

    if(money2 >= loan)
    {
        user[number].chang_loan(-1 * loan);
        user[number].change_loan_date(-1 * user[number].return_loan_date());

        cout << "your loan is payed" << endl;

        if(money2 > loan)
        {
            user[number].change_money(money2 - loan);
        }


    }
    else
    {
        user[number].chang_loan(-1 * loan);
    }
}
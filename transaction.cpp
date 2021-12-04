#include<iostream>
#include<exception>
#include"classes.hpp"


void transfer(USER_ID * user , string command , int user_num)
{
    tm * today;
    string username;
    string username2;
    string ip;
    string money;
    int money2;
    int credit;
    int pos = 9;
    int i = 0;
    bool exist = false;
    int number = -1;
    int number2 = -1;
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
            username2 = get_str(command , ':' , &pos);
        }
        else
        {
            pos = 0;
        }
        
    }

    while (number2 == -1)
    {
        if (i > 0 || pos == 0)
        {
            cout << "Enter username of destination account -> ";
            cin >> username2;
        }
        
        try
        {
            number2 = chek_username(user , username2 , user_num);     
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }
        
        i++;
    }

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

    credit = user[number].return_money();

    if (credit < money2)
    {
        throw(out_of_range("your credit is not enough!!!!"));
    }
    else
    {
        user[number2].change_money(money2);
        user[number].change_money(-1 * money2);
    }
    
    

}






void diposit_withdraw(USER_ID * user , BANK_ID * bank ,string command , int user_num)
{
    tm * today;
    string username;
    string ip;
    string money;
    int money2;
    int credit;
    int pos = 8;
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

    if(command.find("deposit"))
    {
        user[number].change_money(money2);
        bank->chang_money(money2);
        return;
    }

    if ( command.find("withdraw") == 0 )
    {
        if ( user[number].return_loan() == 0 )
        {
            if (bank->return_money() >= money2)
            {
                credit = user[number].return_money();

                if (credit < money2)
                {
                    throw(out_of_range("your credit is not enough!!!!"));
                }
                else
                {
                    user[number].change_money(-1 * money2);
                    bank->chang_money(-1 * money2);
                }
            }
            else
            {
                cerr << "The Bank is broken!!!!!!" << endl;
                bank->chang_broken();
            }
            
            
        }
        else
        {
            cerr << "you have to repayed your loan first!!!" << endl;
        }
    }
    

}

int chek_money(string money)
{
    int money2;

    money2 = stoi(money);

    return money2;
    
}
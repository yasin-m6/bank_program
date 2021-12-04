#include<iostream>
#include<iomanip>
#include<ctime>
#include<new>
#include<exception>
#include"classes.hpp"

USER_ID * create_newuser(USER_ID * user , string command , int * user_num)
{
	string name;
	string cart;
	string ip_add;
	string date;
	int number;
	int flag = 0;
	int pos = 7;
	bool exist;
	int i = 0;
	cout << "number : " << *user_num << endl;

	if (*user_num > 9000)
	{
		throw(out_of_range("you cant create more than 9000 account!!"));
	}
	

	if (user_num > 0)
	{
		user = add_user(user , user_num);
	}
	
	if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
    {
        name = get_str(command , ':' , &pos);
    }
	else
	{
		command = "\0";
	}
	
	do
	{

		flag = 0;
		if(command.length() == 0 || i > 0)
		{
			name = user[(*user_num)].get_username();
		}
		

		for (size_t j = 0; j < *user_num; j++)
		{
			if ( name == user[j].return_username() )
			{
				cerr << "Error , this name is used for another user!!!" << endl;
				flag = 1;
				break;
			}
			
		}
		
		if (flag == 0)
		{
			try
			{
				user[(*user_num)].set_username(name);
				break;
			}
			catch(invalid_argument &p)
			{
				cout << "Error , " << p.what() << endl;
			}
		}

		i++;
		

	}while(1);

	cout << command[pos-1] << endl;

	if(command[pos - 1] == ':')
	{
		
		ip_add = get_str(command , '\0' , &pos);
	}

	do
	{
		
		if(ip_add.length() == 0)
		{
			ip_add = user[*user_num].get_ip();
			pos = 0;
		}

		exist = true;

		try
		{
			exist = chek_correct_ip(ip_add);
			cout << "aim2" << endl;
			if (exist == true)
			{
				exist = chek_ip(user , ip_add , *user_num);
			}
			
		}
		catch(invalid_argument &e)
		{
			std::cerr << e.what() << endl;
		}
		
		if(exist == false)//vaghti hich ip moshabehi nabashad
		{
			user[*user_num].set_ip(ip_add);
			cout << "e" << endl;
			break;
		}
		
		
	} while (1);
	


	do
	{
		flag = 0;
		cart = user[*user_num].get_cart_number();

		for (size_t i = 0; i < *user_num; i++)
		{
			if( cart == user[i].return_cart() )
			{
				cerr << "this number used for another cart!!!" << endl;
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			cout << "its set" << endl;
			user[*user_num].set_cart_number(cart);
			break;
		}
		


		
	} while (1);
	
	return user;
}

USER_ID * add_user(USER_ID * user , int * user_num)
{
	USER_ID * user2 = new(nothrow) USER_ID[ *(user_num) + 1 ];
	if (!user2)
	{
		cerr << "Error in memmory allocation!!!" << endl;
		return user;
	}
	

	for (size_t i = 0; i < *user_num ; i++)
	{
		user2[i] = user[i];
	}


	delete[] user;
	
	return user2;
}

bool new_ip(USER_ID * user , string command , int user_num , int pos)
{
	tm * today;
	string username;
	string ip;
	int number = -1;
	int i = 0;
	bool exist = false;
	char confirmation;

	new_time(today);

	cout << "pos : " << command[pos] << endl;

	if (pos < command.length() && isspace(command[pos]) != isspace(' ') )
    {
        username = get_str(command , ':' , &pos);
		cout << username << endl;
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
    
    while (pos == 0 && exist == true)
	{
		cout << "Enter new ip : ";
		cin >> ip;

		exist == true;

		try
		{
			exist = chek_correct_ip(ip);
			if (exist == true)
			{
				exist = chek_ip(user , ip , user_num);
			}
				
		}
		catch(invalid_argument & e)
		{
			cerr << e.what() << endl;
		}
	}

	cout << "n" << endl;

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
			return false;
		}
			
	}
	
	cout << "m" << endl;
	
	user[number].set_ip(ip);

	if ( command.find("another") < command.length())
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
	
}

string * add_ip(string * ip_list , int number)
{
	string * new_list = new(nothrow) string[number + 1];
	if (!new_list)
	{
		cerr << "Error in memmory allocation!!!" << endl;
		return ip_list;
	}

	for (size_t i = 0; i < number; i++)
	{
		new_list[i] = ip_list[i];
	}
	
	delete[] ip_list;

	return new_list;
	
}


void renewal(USER_ID * user , string command , int user_num)
{
	//mablagh tamdid hesab : 10$

	tm * date;
	string username;
	string ip;
	int money = 0;
	int pos;
	int number = -1;
	bool exist = false;
	int i = 0;
	char confirmation;

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

		exist = false;
        
        try
        {
            exist = chek_correct_ip(ip);
			if (exist == true)
			{
				exist = chek_ip(user , ip , user_num);
			}
			     
        }
        catch(invalid_argument & e)
        {
            cerr << e.what() << endl;
        }		

        i++;
        
    }

	while (1)
	{
		cout << "for renewal you need to pay 10$ " << endl << "are you want to renewal your account ?" << endl;
		cout << "Y : yes \t&\tN : no" << endl;
	
		confirmation = getchar();

		if (confirmation == 'N')
		{
			cout << "renewal is ondone" << endl;
			return;
		}
		else if(confirmation == 'Y')
		{
			if (user[number].return_money() > 10)
			{
				user[number].set_date(date);
				cout << "your account is renewal" << endl;
			}
			else
			{
				money = 10 - user[number].return_money();
				user[number].chang_loan(money);
				user[number].change_money(-1 * (10 - money));
			}

			return;
		
		}
		else if(confirmation != 'Y' && confirmation != 'N')
		{
			cerr << "invalid input!!!!" << endl;
		}
	}
	
}

string get_str(string command , char end , int*pos)
{
	string new_str;

	size_t i = *pos;

	for ( ; i < command.length(); i++)
	{
		if (command[i] == end)
		{
			break;
		}
	
    }
	new_str = command.substr(*pos , i-(*pos) );

	*pos = i+1;

	return new_str;
}

int chek_username(USER_ID * user , string username , int user_num)
{
    int flag = 0;
    
    if (isalpha(username[0]) == isalpha('a') )
    {
        for (size_t i = 1; i < username.length() ; i++)
        {
            if (isalnum(username[i]) != isalnum('a') )
            {
                throw(invalid_argument("invalid username contain by alphabet and numbers!!!"));
            }
                
        }
            
    }
    else
    {
        throw(invalid_argument("username has to srart with an alphabet!!!"));
    }


    size_t i = 0;

    for (; i < user_num ; i++)
    {
        if (username == user[i].return_username() )
        {
            flag = 1;
            break;
            
            
        }
    }



    if(flag == 0)
    {
        cerr << "there is no account with this username" << endl;
        return -1;
    }
    else
    {
        return i;
    }
    
}

bool chek_correct_ip(string ip)
{
    int num = 0;
    int number_part = 0;
	int dot = 0;

    if (isdigit(ip[0]) == isdigit('1'))
    {
        number_part = 1;
    }
    

    for (size_t i = 0; i < ip.length(); i++)
    {
        if ( (isdigit(ip[i]) != isdigit('1')) && (ip[i] != '.') )
        {
            throw invalid_argument ("an invalid ip is contain numbers and . ");
        }
        
    }
    
    
    size_t i = 0;

	for ( ; i < ip.length(); i++)
	{

		if( isdigit(ip[i]) == isdigit('1') )
		{
			num = ( num * 10 ) + static_cast<int>( ip[i] ) - 48; 
		}
		else if(ip[i] == '.')
		{
            dot++;
            if (num > 255)
			{
				throw invalid_argument("invalid ip!!! , numbers has to be between 0 to 255");
			}
			else if ( isdigit(ip[i+1]) == isdigit('1') )
			{
				number_part++;
				num = 0;
				//baraye fahmidan tedad noghat va bakhsh adadi
			}
            
		}

	}


    if (number_part == 4 && dot == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
        
}


bool chek_ip(USER_ID * user , string ip , int user_num )
{
    
    int ip_number = 0;

    cout << "a" << endl;
	
    for (size_t i = 0; i < user_num ; i++)
    {
        cout << "b" << i << endl;
        ip_number = user[i].return_ip_number();

        for (size_t j = 0; j < ip_number; j++)
        {
            cout << "c" << j << endl;
            if (ip == user[i].return_ip(j) )
            {
                return true;
            }
            
        }
    }
    

    cout << "d" << endl;

    return false;
    
}
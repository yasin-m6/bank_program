#ifndef MYBANK
#define MYBANK
	
	
	using namespace std;


	/*struct TRANSACTION
	{
		int money;
		string activity_type;
	};*/

	struct DATE
	{
		int day;
		int month;
		int year;
	};
	
	

	class USER_ID
	{
		public:
			string get_username();
			void set_username(string username);
			string get_cart_number();
			void set_cart_number(string );
			void set_date(tm *);
			string return_username();
			string return_cart();
			string get_ip();
			void set_ip(string);
			int return_ip_number();
			string return_ip(int);
			void change_money(int);
			int return_money();
			void chang_loan(int);
			int return_loan();
			void change_loan_date(int);
			unsigned int return_loan_date();
			void change_profit_date(int);
			unsigned int return_profit_date();
			void print_information();
			
		private:
			string username;
			string cart_number;
			int money = 0;
			DATE eftetah;
			DATE engheza;
			int loan;
			unsigned int loan_date;
			unsigned int profit_date;
			string * ip_list;
			int ip_num = 0;
			
	};

	class BANK_ID
	{
		public:
			void chang_money(int);
			unsigned int return_money();
			void chang_loan(int);
			unsigned long int return_loan();
			void chang_user_num(int);
			unsigned int return_user_num();
			void chang_broken();
			bool return_broken();
			void print_information();

		private:
			int user_num = 0;
			unsigned long int loan = 0;
			unsigned int money;
			bool broken = false;
	};

	USER_ID * create_newuser( USER_ID * user , string command , int * user_num );
    USER_ID * add_user( USER_ID * , int * user_num);
    int chek_username( USER_ID * , string , int );
    bool chek_ip( USER_ID * user, string , int );
    int chek_money( string );
	bool check_cart_date( tm * );
	int passed_days( time_t *);
	bool chek_correct_ip( string );
	bool new_ip( USER_ID * user, string , int , int );
	void renewal( USER_ID * user, string , int );
	void transfer( USER_ID * user, string , int );
	void diposit_withdraw( USER_ID * user, BANK_ID * , string , int );
	void profits( USER_ID *user, string , int , int * );
	void loan( USER_ID * user, BANK_ID * , int , string );
	void pay_loan( USER_ID * user, BANK_ID * , int , string );
	void new_time( tm * );
	bool check_cart_date( tm * );
	int passed_days( time_t * );
	string get_str(string command , char end , int*pos);
	string * add_ip(string * ip_list , int number);
	

#endif
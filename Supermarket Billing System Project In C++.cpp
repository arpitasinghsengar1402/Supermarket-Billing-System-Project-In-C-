#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};
void shopping:: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t__________________________\n";
	cout<<"\t\t\t\t                          \n";
	cout<<"\t\t\t\t   SUPERMARKET MAIN MENU  \n";
	cout<<"\t\t\t\t                          \n";
	cout<<"\t\t\t\t__________________________\n";
	cout<<"\t\t\t\t                          \n";
	cout<<"\t\t\t\t|  1) ADMINISTRATOR  |\n";
	cout<<"\t\t\t\t__________________________\n";
	cout<<"\t\t\t\t|  2) BUYER          |\n";
	cout<<"\t\t\t\t__________________________\n";
	cout<<"\t\t\t\t|  3) EXIT           |\n";
	cout<<"\t\t\t\t__________________________\n";
	cout<<"\t\t\t\t PLEASE SELSECT!";
	cin>>choice;
	
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t PLEASE LOGIN \n";
			cout<<"\t\t\t ENTER EMAIL  \n";
			cin>>email;
			cout<<"\t\t\t Password     \n";
			cin>>password;
			
			if(email=="robby@gmail.com"&& password=="robby@123")
			{
				administrator();
         	}
         	else
         	{
         	   cout<<"Invalid email/password";
					
			}
			break;
	    
	
	case 2:
		{  
			   buyer();
		}
	case 3:
	    {
			 
			       exit(0);
	    }
		default :
			{
				cout<<"Please select from the given options";
				
			}
    }
goto m;
}
void shopping::administrator()
{
    m:
	int choice;
	cout<<"\n\n\n\t\t\t  ADMINISTRATION MENU";
	cout<<"\n\t\t\t|_____1) ADD THE PRODUCT_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) MODIFY THE PRODUCT__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) DELETE THE PRODUCT__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____4) BACK TO MAIN MENU___|";
	
	cout<<"\n\n\t PLEASE ENTER YOUR CHOICE";
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"INVALID CHOICE!";
		
	}
	goto m;
}
void shopping::buyer()
{
	m:
		int choice;
		cout<<"\t\t\t  BUYER   \n";
		cout<<"\t\t\t____________________\n";
		cout<<"                          \n";
		cout<<"\t\t\t 1) BUY PRODUCT     \n";
		cout<<"                          \n";
		cout<<"\t\t\t 2) GO BACK         \n";
		cout<<"\t\t\t ENTER YOUR CHOICE :  ";
		cin>>choice;
		
		switch (choice)
		{
			case 1:
				receipt();
				break;
			case 2:
			    menu();
			default :
				cout<<"INVALID CHOICE";
				
		}
		goto m;
		
		
		
}
 
void shopping :: add()
{
	m: 
	fstream data;
	int c;
	int token=0;
	float p,d;
	string n;
	
	cout<<"\n\n\t\t\t ADD NEW PRODUCT";
	cout<<"\n\n\t PRODUCT CODE OF THE PRODUCT";
	cin>>pcode;
	cout<<"\n\n\t NAME OF THE PRODUCT ";
	cin>>pname;
	cout<<"\n\n\t PRICE OF THE PRODUCT";
	cin>>price;
	cout<<"\n\n\t DISCOUNT OF THE PRODUCT";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
	 data.open("database.txt", ios::app| ios::out);
	 data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
      data.close();
    }
else 
{
	data>>c>>n>>p>>d;
	while(!data.eof())
	{
		if(c==pcode)
		{
			token++;
			
		}
		data>>c>>n>>p>>d;
	}
	data.close();
	
	if(token==1)
	goto m;
	else
	{
		data.open("database.txt",ios::app| ios::out);
		data<<"  "<<pcode<<"  "<<price<<"  "<<dis<<"\n";
		data.close();
	}
	
}
    cout<<"\n\n\t\t RECORD INSERTED ! ";
}

void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p,d;
	string n;
	cout<<"\n\n\t\t  MODIFY THE RECORD";
	cout<<"\n\n\t\t  PRODUCT CODE  : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n FILE DOESNOT EXIST !";
		
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\n\t\t  PRODUCT NEW CODE :";
				cin>>c;
				cout<<"\n\n\t\t  NAME OF THE PRODUCT :";
				cin>>n;
				cout<<"\n\n\t\t  PRICE :";
				cin>>p;
				cout<<"\n\n\t\t  DISCOUNT :";
				cin>>d;
				data1<<"  "<<c<<"  "<<p<<"  "<<d<<"\n";
				cout<<"\n\n\t\t Record Edited ";
				token++;
				
			}
			else
			{
				data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove(" database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
	    {
		cout<<"\n\n RECORD NOT FOUND SORRY!";
		
	    } 
	}

}


void shopping :: rem()
{
  fstream data,data1;
  int pkey;
  int token=0;
  cout<<"\n\n\t DELETE PRODUCT";
  cout<<"\n\n\t PRODUCT CODE:";
  cin>>pkey;
  data.open("database.txt",ios::in);
  if(!data)
  {
  	cout<<"FILE DOESNOT EXIST";
  }
  else
  {
  	data1.open("database1.txt",ios::app|ios::out);
  	while(!data.eof())
	  {
	  	if(pcode==pkey)
	  	{
	  		cout<<"\n\n\t PRODUCT DELETED SUCCESFULLY";
	  		token++;
	  		
		}
		else
		{
			data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
			
		}
		data>>pcode>>pname>>price>>dis;
       }
       data.close();
       data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");
       
       if(token==0)
       {
       	cout<<"\n\n RECORD NOT FOUND";
       	
	   }
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|______________________________\n";
	cout<<"ProNo\t\tname\t\tprice\n";
	cout<<"\n\n|______________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
		
	}
	data.close();
	
}

void shopping :: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	cout<<"\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n EMPTY DATABASE";
		
	}
    else
    {
    	data.close();
    	list();
    	cout<<"\n___________________________\n";
    	cout<<"\n|                          \n";
    	cout<<"\n    PLEASE PLACE THE ORDER \n";
		cout<<"\n|                          \n";
		cout<<"\n___________________________\n";
		do
		{   
		    m:
			cout<<"\n\n ENTER PRODUCT CODE:";
			cin>>arrc[c];
			cout<<"\n\n ENTER THR PRODUCT QUANTITY:";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n DUPLICATE PRODUCT CODE. PLEASE TRY AGAIN!";
					goto m;
					
				}
			}
			c++;
			cout<<"\n\n DO YOU WANT TO BUY ANOTHER PRODUCT? IF YES THEN PRESS Y ELSE NO";
			cin>>choice;
			
		}	
		while(choice =='y');
		
		cout<<"\n\n\t\t\t_______________RECIPT_________________\n";
		cout<<"\n PRODUCT NO\t PRODUCT NAME\t PRODUCT QUALITY\t PRICE\t AMOUNT WITH DISCOUNT\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
					
				}
				data>>pcode>>pname>>price>>dis;
				
			}
		}
		data.close();
		
     }
     cout<<"\n\n_____________________________";
     cout<<"\n TOTAL AMOUNT  : "<<total;
}
int main()
{
	shopping s;
	s.menu();
}

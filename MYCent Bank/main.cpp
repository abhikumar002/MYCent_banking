#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<fstream>
#include <cctype>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include<sstream>
using namespace std;

class bank
{
  private:
  	 int acno;
     char name[100];
	 int deposite;	
	 char type;

	 
  public :
  	void open_acc();
  	void dis_acc() const;
  	void modify();
  	void dep_money(int);
  	void with_money(int);
  	void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
};

void bank::open_acc()
{	
	cout<"              \n OPEN ACCOUNT \n                ";
	cout<<"Enter account no. :  ";
	cin>>acno;
	cout<<"Enter your full name :  ";
	cin.ignore();
	cin.getline(name,100);
	cout<<"\n What type of account you want to open saving(s) or current(c)";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter amount for deposite : ";
	cin>>deposite;
	cout<<"\n Your account is created";
}
void bank::dis_acc() const
{
	
	
	cout<"              \n DISPLAY ACCOUNT \n                ";
	cout<<"Account no. "<<acno;
	cout<<"\nFull name :  "<<name;
	cout<<"\n Type of account that you open :  "<<type;
	cout<<"\n Deposite amount : "<<deposite<<endl;

}
void bank::modify()
{
	cout<"              \n MODIFY ACCOUNT \n                ";
	cout<<"Enter account no. :  ";
	cin>>acno;
	cout<<"Enter your full name :  ";
	cin.ignore();
	cin.getline(name,100);
	cout<<"\n What type of account you want to open saving(s) or current(c)";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter amount for deposite : ";
	cin>>deposite;
	//cout<<"\n Update succesfully\n";
}
void bank::dep_money(int x)
{
  deposite=deposite+x;
}
void bank::with_money(int x)
{
	deposite=deposite-x;
}
void bank::report() const
{
	cout<<"\n";
    cout.width(15);
	cout.fill(' ');
	cout.setf(ios::left,ios::adjustfield);
	cout<< acno <<setw(20);
	//------------------------------------------------
	cout.width(25);
	cout.fill(' ');
	cout.setf(ios::left,ios::adjustfield);
	cout<< name <<setw(10);
	//------------------------------------------------
	cout.width(14);
	cout.fill(' ');
	cout.setf(ios::left,ios::adjustfield);
	cout<< type <<setw(10);
	//------------------------------------------------
    cout.width(9);
	cout.fill(' ');
	cout.setf(ios::left,ios::adjustfield);
	cout<<deposite<<endl;
	//------------------------------------------------
}
int bank::retacno() const
{
	return acno;
}
int bank::retdeposit() const
{
	return deposite;
}
char bank::rettype() const
{
	
	return type;
}


	
//Functions
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
void firstmain();
void submain();
void login();
void forgot();
void signup();
void homepage();


int main()
{
firstmain();
submain();          
getch();      
return 0;
}
void firstmain()
{
	system("cls");
printf("\t\t=====================================================================================\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                            -----------------------------                          |\n");
printf("\t\t|                               MY CENT MANAGING SYSTEM                             |\n");
printf("\t\t|                            -----------------------------                          |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                                                                   |\n");
printf("\t\t|                                 BROUGHT TO YOU BY                                 |\n");
printf("\t\t|                             | Abhishek kumar Gupta  |                             |\n");
printf("\t\t|                            | Uni. Roll No. - 1915327 |                            |\n");
printf("\t\t=====================================================================================\n\n\n");
cout<<"\t\tPress Enter to continue : ";
cin.get();
}
void submain()
{
        int choice;
        system("cls");
        cout<<"\n\n WELCOME TO THE MENU OF OUR SYSTEM\n\n\n";
        cout<<"Select any of the option ->\n";
        cout<<"Type 1 for LOGIN"<<endl;
        cout<<"Type 2 if you FORGOT ACCOUNT details "<<endl;
        cout<<"Type 3 for New user SIGNUP "<<endl;
        cout<<"Type 4 to EXIT "<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
                {
                case 1:
                        login();
                        break;

                case 2:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this MYCENT Bank Management System. \nThis program is created indiviual by Abhishek Kumar Gupta, Roll no. 1915327(CSE).\n\n";
                        cin.get();
                        exit(0);
                        break;
                case 3:
                        signup();
                        break;
                default:
                        system("cls");
                        cout<<"\nYou've made a wrong choice by mistake, please enter correct choice again!\n"<<endl;
                        submain();
                }
}
void login()
{
        int count;
        string user,pass,u,p,cp,nm,em,ph,addrs,occ,ag;
        system("cls");
        cout<<"Please enter the following details"<<endl;
        cout<<"USERNAME : ";
        cin>>user;
        cout<<"PASSWORD : ";
        cin>>pass;
        ifstream input("database.txt");
        string line;
        while(getline(input,line))
        {
          stringstream ss(line);
          getline(ss,u,' ');
          getline(ss,p,' ');
          getline(ss,cp,',');
          getline(ss,nm,',');
          getline(ss,ag,',');
          getline(ss,em,',');
          getline(ss,ph,',');
          getline(ss,addrs,',');
          getline(ss,occ);
                if(u==user && p==pass)
                {
                        count=1;
                        system("cls");

                }
        }
        
        input.close();
        if(count==1)
        {
                cout<<"\nHello "<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in!\n";
                //cin.get();
                //cin.get();
                Sleep(2000);
                system("cls");
                homepage();
        }
        else
        {
                system("cls");
                cout<<"\nLOGIN ERROR\nPlease check your username and password again!\n\n";
                cin.get();
                cin.get();
                main();
        }
}
void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgot anything? We're here for help\n\n";
        cout<<"Type 1. to Search your id by username"<<endl;
        cout<<"Type 2. to Search your id by password"<<endl;
        cout<<"Type 3. for Main menu\n\n"<<endl;
        cout<<"Enter your choice : \n";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        { 
                            
                                if(su==searchuser)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        cout<<su<<endl;
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\n Account found\n";
                                cout<<"\nYour password is "<<sp<<endl;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                system("cls");
                                cout<<"\nSorry, Your userID is not found in our database\n\n";
                                cout<<"\n Try again by filling correct details\n";
                                cin.get();
                                cin.get();
                                forgot();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id username is : "<<su2<<endl;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                system("cls");
                                cout<<"Sorry, We cannot found your password in our database \n\n";
                                cout<<"\n Please try again by filling correct details \n";
                                cin.get();
                                cin.get();
                                forgot();
                        }
                        break;
                }
                case 3:
                {
                        cin.get();
                        system("cls");
                        main();
                        break;
                }
                default:
                        system("cls");
                        cout<<"\nSorry, You entered wrong choice. Kindly try again\n"<<endl;
                        cin.get();
                        forgot();
        }
}
void signup()
{
	
        system("cls");
        string reguser,pp,regpass,conpass,name,occupation,address,email,age,phone;
        getline(cin,pp);
        cout<<"\nEnter bank branch code : ";
        getline(cin,occupation);
        
        if(occupation=="Cent123")
        {
        cout<<"Enter the username :";
        getline(cin,reguser);
        cout<<"\nEnter the password :";
        getline(cin,regpass);
        cout<<"\nConfirm password : ";
        getline(cin,conpass);
        if(conpass!=regpass)
        {
          cout<<"\nPassword does not match please confirm again\n";
          cout<<"\nConfirm password : ";
          cin>>conpass;
          }
          cout<<"\nEnter your full name : ";
          getline(cin,name);
          cout<<"\nEnter your age in years : ";
          getline(cin,age);
          cout<<"\nEnter your email : ";
          getline(cin,email);
          cout<<"\nEnter phone number : ";
          getline(cin,phone);
          cout<<"\nEnter your permanent address : ";
          getline(cin,address);
          
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<" "<<regpass<<" , "<<name<<" , "<<age<<" , "<<email<<" , "<<phone<<" , "<<address<<endl;
        system("cls");
        cout<<"\nRegistration Successful\n";
        cout<<"We are glad that you registered with us";
        cout<<"\n Please login with your details to enjoy exciting features of our system ";
        cin.get();
        cin.get();
        }
        else
        {
        	cout<<"Please Enter valid code for branch. Software use only by members of the branch";
	        cin.get();
	        cin.get();
		}
        main();


        cout<<"\n\n";

}
void homepage()
{
	int x,n,num;
    bank obj;
    do{
	 	system("cls");
    	cout<<"                    MYCENT MANGEMENT SYSTEM                  "<<endl;
    cout<<" \n\n\t 1) OPEN ACCOUNT \n\n\t 2) DEPOSITE MONEY \n\n\t 3) WITHDRAW MONEY \n\n\t 4) BALANCE ENQUIRY \n\n\t 5) ALL ACCOUNT HOLDER LIST \n\n\t 6) CLOSE AN ACCOUNT \n\n\t 7) MODIFY AN ACCOUNT \n\n\t 8) Sign Out \n";
    cout<<"Select option from above"<<endl;
	int choose;
	cin>>choose;
	system("cls");

	switch(choose)
	{
		case 1 : 
		    write_account();
		    break;
		    
		case 2 :
			cout<<"\n\n\tEnter the account number. = "; cin>>num;
            deposit_withdraw(num,1);
			break;
			
		case 3 :
			cout<<"\n\n\tEnter the account number. = "; cin>>num;
            deposit_withdraw(num,2);
			break;
			
		case 4 :
			cout<<"\n\n\tEnter the account number. = "; cin>>num;
             display_sp(num);
			break;
			
		case 5 :
            display_all();
            break;
			
		case 6 :
			cout<<"\n\n\tEnter the account number. = "; cin>>num;
            delete_account(num);
            break;
            
		case 7 :
			cout<<"\n\n\tEnter the account number. = "; cin>>num;
            modify_account(num);  
            break;
            
        case 8 :
        	x='x';
       	    cout<<"\nAre you Sure to Sign Out : y"<<endl;
	        cout<<"If cancel :: n" <<endl;

	    x=getch();
	    if(x=='n'|| x=='N')
	  {
	  	
	      homepage();
	      break;
	  }
       else if(x=='y'|| x=='Y')
        {
        	 cout<<"\nRedirecting to login menu."<<endl;
      	     cout<<"Loading..." <<endl;
      	     Sleep(1000);
	    	 submain();
        	 break;
        }
        else 
        {
          cout<<"Inavlid input";
		  cin.get();
          cin.get();
          homepage();
         }
         break;
	    default :
		    cout<<"This is not exist try again \n";
		}
		
		cin.get();
      	cin.get();
    	cout<<"\nRedirecting to main menu."<<endl;
      	cout<<"Loading..." <<endl;
        Sleep(2000);
         x='y';
       	
	     // if(x=='n'|| x=='N')
	      //exit(0);
       }while(x=='y'|| x=='Y');
}

void write_account()
{
	bank ac;
	ofstream outfile;
	outfile.open("account.dat",ios::binary|ios::app);
	ac.open_acc();
	outfile.write(reinterpret_cast <char*> (&ac),sizeof(bank));
	outfile.close();
}
void display_sp(int n)
{
	bank ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	 cout<<"File could not be open!!Press any key...";
	 return ;
    }
    cout<<"\n\n Balance Detail"<<endl;
   while(inFile.read(reinterpret_cast <char*> (&ac),sizeof(bank)))
    {
    	if(ac.retacno() == n)
          {
	  		ac.dis_acc();
    		flag = true;
	      }
	 }
	
	inFile.close();
	if(flag==false)
	  cout<<"\n\nAccount no. does not exit.\n";
}
void modify_account(int n)
{
	bool found=false;
	bank ac;
	fstream File;
	File.open("account.dat",ios::binary | ios::in | ios::out);
	if(!File)
	  {
	  	cout<<"File could not be open !! Press any key...";
	  	return;
	  }
	  while(!File.eof() && found==false)
	  {
	  	File.read(reinterpret_cast <char*>(&ac),sizeof(bank));
	     if(ac.retacno()== n)
	  	  {
    	  	ac.dis_acc();
	  	  	cout<<"\n Enter the new details of account"<<endl;
	  	  	ac.modify();
	  	  	int pos=(-1)* static_cast<int>(sizeof(bank));
	  	  	File.seekp(pos,ios::cur);
	  	  	File.write(reinterpret_cast<char*> (&ac),sizeof(bank));
	  	  	cout<<"\n\n\tRecord Updated\n";
	  	  	found=true;
		  }
	  }
	  File.close();
	  if(found==false)
	    cout<<"\nRecord not found"<<endl;
}
void delete_account(int n)
{
	bank ac;
	bool found=false;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open!!Press any key...";
		return ;
	}
	
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	 while(inFile.read(reinterpret_cast <char*> (&ac),sizeof(bank)))
	   {
	  	if(ac.retacno()!=n)
	   	 {
	   	 	outFile.write(reinterpret_cast <char*> (&ac),sizeof(bank));	   	 	
		 }
		 else
		    found=true;
	   }
	   
	   inFile.close();
	   outFile.close();
	   remove("account.dat");
	   rename("Temp.dat","account.dat");
	   
	   if(found==true)
	   cout<<"\n\n\tRecord Deleted\n";
	   else
	   cout<<"\n\n\tRecord not found";
}
void display_all()
{
	bank ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open!!Press any key...";
		return ;
	}
	 
	 cout<<"\n\n\tACCOUNT HOLDER LIST\n\n";
	 cout<<"Acc no.          name                  Type          Balance";
	 while(inFile.read(reinterpret_cast <char*> (&ac),sizeof(bank)))
	 {
	 	ac.report();
	 }
	 inFile.close();
}
void deposit_withdraw(int n,int option)
{
	int amt;
	bool found=false;
	bank ac;
	fstream File;
	File.open("account.dat",ios::binary | ios::in | ios::out);
	if(!File)
	{
		cout<<"File could not be open!!Press any key...";
		return ;
	}
	
	while(!File.eof() && found==false)
	{
		int find=false;
		File.read(reinterpret_cast <char*> (&ac),sizeof(bank));
           if(ac.retacno()==n)
           {
          	   ac.dis_acc();
           	   if(option==1)
           	   {
           	   	cout<<"\n\n\tDeposite Amount\n\n";
           	   	cout<<"Enter the amount to be deposited";
           	   	cin>>amt;
           	   	ac.dep_money(amt);
			   }
			   else if(option==2)
			   {
			   	cout<<"\n\n\tWithdraw Amount\n\n";
			   	cout<<"Enter the amount you want to withdraw";
			   	cin>>amt;

			    	   int bal=ac.retdeposit()-amt;
			    	   if((bal<500 && ac.rettype()=='S' || bal<1000 && ac.rettype()=='C'))
			   	          { cout<<" \nInsufficient balance \n"<<endl; find=true; }
			   	   else
			   	     ac.with_money(amt);
			   }
			   	     int pos= (-1)*static_cast <int> (sizeof(ac));
			   	     File.seekp(pos,ios::cur);
			   	     File.write(reinterpret_cast <char*> (&ac), sizeof(bank));
			   	     if(find==false)
			         cout<<"\n\n\tRecord Updated";
           	         found=true;
		   }
	}
	File.close();
	if (found==false)
	   cout<<"Record Not Found";
}



#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<fstream>
#include <cctype>
#include <iomanip>
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

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);

int main()
{   

	int x,n,num;
    bank obj;
    do{
    	system("cls");
    	cout<<"                    BANK MANGEMENT SYSTEM                  "<<endl;
    cout<<" \n\n\t 1) OPEN ACCOUNT \n\n\t 2) DEPOSITE MONEY \n\n\t 3) WITHDRAW MONEY \n\n\t 4) BALANCE ENQUIRY \n\n\t 5) ALL ACCOUNT HOLDER LIST \n\n\t 6) CLOSE AN ACCOUNT \n\n\t 7) MODIFY AN ACCOUNT \n\n\t 8) EXIT \n";
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
        	 exit(0);
        	 break;
        	 
	    default :
		    cout<<"This is not exist try again \n";				    
	}
	
	
	cout<<"\nDo you want to select next option then press : y"<<endl;
	cout<<"if you want to exit then press :: n" <<endl;

	x=getch();
	    if(x=='n'|| x=='N')
	      exit(0);
        }while(x=='y'|| x=='Y');
        
getch();      
return 0;
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



//Bookshop management system
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;

class bookshope
{
	public:
		void control_panel(); 
		void add_book();
		void show_books();
		void check_book();
		void update_book();
		void del_book();
};

	void bookshope::control_panel()
	{
		system("cls");
		cout<<"\n\n\t\t\t\tControl Panel";
		cout<<"\n\n 1. Add New Book";
		cout<<"\n 2. Display Books";
		cout<<"\n 3. Check Specific Book";
		cout<<"\n 4. Update Book";
		cout<<"\n 5. Delete Book";
		cout<<"\n 6. Exit";
	}
	
	void bookshope::add_book()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,a_name,b_id;
		cout<<"\n\n\t\t\t\t ADD New Book";
		cout<<"\n\n Book ID : ";
		cin>>b_id;
		cout<<"\n\n\t\t\t Book Name : ";
		cin>>b_name;
		cout<<"\n\n Author Name : ";
		cin>>a_name;
		cout<<"\n\n\t\t\t No. of Copies : ";
		cin>>no_copy;
		file.open("E://book.txt",ios::out|ios::app);
		file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
		file.close();
	}
	
	void bookshope::show_books()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,b_id,a_name;
		cout<<"\n\n\t\t\t\tShow All Books";
		file.open("E://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID    Book    Author    No. of Copies\n\n";
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<b_id<<"     "<<b_name<<"     "<<a_name<<"\t\t"<<no_copy<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
		}
	}
	
	void bookshope::check_book()
	{
		system("cls");
		fstream file;
		int no_copy,count=0;
		string b_id,b_name,a_name,b_idd;
		cout<<"\n\n\t\t\t\tCheck Specific Book";
		file.open("E://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tCheck Specific Book";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\n\t\t\tName : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\n\t\t\tNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}
	
	void bookshope::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		file1.open("E://book1.txt",ios::app|ios::out);
		file.open("E://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("E://book.txt");
		rename("E://book1.txt","E://book.txt");
	}
	
	void bookshope::del_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("E://book1.txt",ios::app|ios::out);
		file.open("E://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("E://book.txt");
		rename("E://book1.txt","E://book.txt");
	}
main()
{
	int choice;
	char x;
	bookshope b;
	p:
	b.control_panel();
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			b.add_book();
			cout<<"\n\n Do You Want to Add another Book (y,n) : ";
			cin>>x;
		    }while(x == 'y');
			break;
		case 2:
			b.show_books();
 			break;
		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;
		case 5:
			b.del_book();
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	getch();
	goto p;
}

/**********************************************************************************************
PROJECT ON LIBRARY MANAGEMENT SYSTEM
MADE BY ISHITA AGRAWAL, XII-B
**********************************************************************************************/

/*********************************************************************************************
HEADER FILES USED
********************************************************************************************/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

/**********************************************************************************************
CLASS TO STORE BOOK DETAILS
**********************************************************************************************/

class book
{
	char bno[6];
	char bname[50];
	char category[20];
	char aname[20];
public:
	void create_book();
	void show_book();
	void modify_book();
	char* retbno();
	char* ret_bname();
	void report();

};

//FUNCTIONS OF CLASS BOOK:

void book::create_book()
{
	cout<<"\n\n\t\t\t\tNEW BOOK ENTRY\n\n";
	cout<<"\nENTER BOOK NUMBER: ";
	cin>>bno;
	cout<<"ENTER BOOK NAME: ";
	gets(bname);
	cout<<"ENTER AUTHOR NAME: ";
	gets(aname);
	cout<<"ENTER CATEGORY: ";
	gets(category);
	cout<<"\n\n!!BOOK RECORD CREATED SUCCESSFULLY!!";
}

void book::show_book()
{
	cout<<"\nBOOK NUMBER: "<<bno;
	cout<<"\nBOOK NAME: ";
	puts(bname);
	cout<<"AUTHOR NAME: ";
	puts(aname);
	cout<<"CATEGORY: ";
	puts(category);
}

void book::modify_book()
{
	cout<<"\nENTER BOOK NUMBER: ";
	cin>>bno;
	cout<<"ENTER NAME: ";
	gets(bname);
	cout<<"ENTER AUTHOR'S NAME: ";
	gets(aname);
	cout<<"ENTER CATEGORY: ";
	gets(category);
}

char* book::retbno()
{
	return bno;
}

char* book::ret_bname()
{
	return bname;
}
void book::report()
{
	cout<<bno<<setw(28)<<bname<<setw(22)<<aname<<setw(25)<<category<<endl;
}

//CLASS ENDS HERE

/**********************************************************************************************
CLASS TO STORE STUDENT DETAILS
**********************************************************************************************/

class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	void create_student();
	void show_student();
	void modify_student();
	char* retadmno();
	char* retstbno();
	int rettoken();
	void addtoken();
	void resettoken();
	void getstbno(char t[]);
	void report();
};

//FUNCTIONS OF CLASS STUDENT:

void student::create_student()
{
	clrscr();
	cout<<"\n\n\t\t\t\tNEW STUDENT ENTRY\n\n";
	cout<<"\nENTER ADMISSION NUMBER: ";
	cin>>admno;
	cout<<"ENTER STUDENT NAME: ";
	gets(name);
	token=0;
	stbno[0]='/0';
	cout<<"\n\n!!STUDENT RECORD CREATED SUCCESSFULLY!!";
}

void student::show_student()
{
	cout<<"\nADMISSION NUMBER: "<<admno;
	cout<<"\nSTUDENT NAME: ";
	puts(name);
	cout<<"NUMBER OF BOOKS ISSUED: "<<token;
	if(token==1)
	{
		cout<<"\nBOOK NUMBER ISSUED: "<<stbno;
	}
}

void student::modify_student()
{
	cout<<"\nENTER ADMISSION NUMBER: ";
	cin>>admno;
	cout<<"ENTER NAME: ";
	gets(name);
}

char* student::retadmno()
{
	return admno;
}

char* student::retstbno()
{
	return stbno;
}

int student::rettoken()
{
	return token;
}

void student::addtoken()
{
	token=1;
}

void student::resettoken()
{
	token=0;
}

void student::getstbno(char t[])
{
	strcpy(stbno,t);
}

void student::report()
{
	cout<<"\t"<<admno<<setw(30)<<name<<setw(10)<<token<<endl;
}

//CLASS ENDS HERE

/**********************************************************************************************
FUNCTIONS USED IN THE PROGRAM
**********************************************************************************************/

void write_book();
void write_student();
void read_book();
void read_student();
void search_book();
void search_student();
void modify_book();
void modify_student();
void delete_book();
void delete_student();
void book_issue();
void book_deposit();
void intro();
void admin_menu();
void student_menu();
void student_details_menu();
void book_details_menu();


/**********************************************************************************************
DECLARING VARIABLES FOR CLASSES AND FILE
**********************************************************************************************/

fstream f_book, f_student;
book b;
student s;

/**********************************************************************************************
THE MAIN FUNCTION OF PROGRAM
**********************************************************************************************/

void main()
{
	int ch;
	intro();
	clrscr();
	do
	{
		cout<<"\n\n\t\t\t\tMAIN MENU\n\n";
		cout<<"\n1. STUDENT MENU";
		cout<<"\n2. ADMINISTRATOR MENU";
		cout<<"\n3. EXIT";
		cout<<"\n\n   ENTER YOUR CHOICE (1-3): ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					clrscr();
					student_menu();
					clrscr();
				}
				break;

			case 2:
				{
					clrscr();
					admin_menu();
					clrscr();
				}
				break;
			case 3: exit(0);

			default :cout<<"INVALID CHOICE";
		}
	}while(ch!=4);
}


/**********************************************************************************************
FUNCTION FOR ADMIN MENU
**********************************************************************************************/

void admin_menu()
{
	clrscr();
	int ch;
	do
	{
		cout<<"\n\n\t\t\t\tADMINISTRATOR MENU\n\n";
		cout<<"\n1. STUDENT DETAILS MENU";
		cout<<"\n2. BOOK DETAILS MENU";
		cout<<"\n3. BACK TO MAIN MENU";
		cout<<"\n\n   ENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					clrscr();
					student_details_menu();
					clrscr();
				}
				break;
			case 2:
				{
					clrscr();
					book_details_menu();
					clrscr();
				}
				break;
			case 3: return;
			default: cout<<"\nINVALID CHOICE";
		}
	}while(ch!=3);
	getch();
}

/**********************************************************************************************
FUNCTION FOR STUDENT MENU
**********************************************************************************************/

void student_menu()
{
	int ch;
	clrscr();
	do
	{
		cout<<"\n\n\t\t\t\tSTUDENT MENU\n\n";
		cout<<"\n1. ISSUE BOOK";
		cout<<"\n2. DEPOSIT BOOK";
		cout<<"\n3. BACK TO MAIN MENU";
		cout<<"\n\n   ENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					clrscr();
					book_issue();
					clrscr();
				}
				break;
			case 2:
				{
					clrscr();
					book_deposit();
					clrscr();
				}
				break;
			case 3: return;
			default: cout<<"\nINVALID CHOICE";
		}
	}while(ch!=3);
	getch();
}

/**********************************************************************************************
FUNCTION FOR INTRODUCTION
**********************************************************************************************/

void intro()
{
	clrscr();
	cout<<"\n\n\n\t\t\tLIBRARY   MANAGEMENT   SYSTEM"<<endl<<endl<<endl;
	cout<<"\n\n\n\n\n\n\n\n\n\n\nMADE BY: ISHITA AGRAWAL";
	cout<<"\nCLASS: XII-B";
	cout<<"\nROLL NUMBER: 14606488";
	cout<<"\nSCHOOL: DAV PUBLIC SCHOOL, SRESHTHA VIHAR";
	getch();
}

/**********************************************************************************************
FUNCTION FOR STUDENT DETAILS MENU
**********************************************************************************************/

void student_details_menu()
{
	clrscr();
	int ch;
	do
	{
		cout<<"\n\n\t\t\t\tSTUDENT DETAILS MENU\n\n";
		cout<<"\n1. ADD STUDENT";
		cout<<"\n2. DISPLAY ALL STUDENTS";
		cout<<"\n3. SEARCH STUDENT";
		cout<<"\n4. MODIFY STUDENT";
		cout<<"\n5. DELETE STUDENT";
		cout<<"\n6. RETURN TO ADMINISTRATOR MENU";
		cout<<"\n   ENTER YOUR CHOICE (1-6):  ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					clrscr();
					write_student();
					clrscr();
				}
				break;

			case 2:
				{
					clrscr();
					read_student();
					clrscr();
				}
				break;

			case 3:
				{
					clrscr();
					search_student();
					clrscr();
				}
				break;

			case 4:
				{
					clrscr();
					modify_student();
					clrscr();
				}
				break;

			case 5:
				{
					clrscr();
					delete_student();
					clrscr();
				}
				break;
			case 6: return;
			default:cout<<"INVALID CHOICE";
		}
	}while(ch!=6);
}

/**********************************************************************************************
FUNCTION FOR BOOK DETAILS MENU
**********************************************************************************************/

void book_details_menu()
{
	clrscr();
	int ch;
	do
	{
		cout<<"\n\n\t\t\t\tBOOK DETAILS MENU\n\n";
		cout<<"\n1. ADD BOOK";
		cout<<"\n2. DISPLAY ALL BOOK";
		cout<<"\n3. SEARCH BOOK";
		cout<<"\n4. MODIFY BOOK";
		cout<<"\n5. DELETE BOOK";
		cout<<"\n6. RETURN TO ADMINISTRATOR MENU";
		cout<<"\n   ENTER YOUR CHOICE (1-6):  ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					clrscr();
					write_book();
					clrscr();
				}
				break;

			case 2:
				{
					clrscr();
					read_book();
					clrscr();
				}
				break;

			case 3:
				{
					clrscr();
					search_book();
					clrscr();
				}
				break;

			case 4:
				{
					clrscr();
					modify_book();
					clrscr();
				}
				break;

			case 5:
				{
					clrscr();
					delete_book();
					clrscr();
				}
				break;
			case 6: return;
			default:cout<<"INVALID CHOICE";
		}
	}while(ch!=6);
}

/**********************************************************************************************
FUNCTION TO ADD A NEW BOOK TO FILE
*********************************************************************************************/

void write_book()
{
	char ch;
	f_book.open("BOOK.DAT",ios::binary|ios::out|ios::app);
	do
	{
		clrscr();
		b.create_book();
		f_book.write((char*)&b,sizeof(b));
		cout<<"\n\nDO YOU WANT TO ADD ANOTHER BOOK? (Y/N): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f_book.close();
}

/**********************************************************************************************
FUNCTION TO ADD A NEW STUDENT TO FILE
**********************************************************************************************/

void write_student()
{
	char ch;
	f_student.open("STUDENT.DAT",ios::binary|ios::out|ios::app);
	do
	{
		s.create_student();
		f_student.write((char*)&s,sizeof(s));
		cout<<"\n\nDO YOU WANT TO ADD ANOTHER STUDENT? (Y/N): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f_student.close();
}

/**********************************************************************************************
FUNCTION TO DISPLAY ALL BOOKS
**********************************************************************************************/

void read_book()
{
	clrscr();
	f_book.open("BOOK.DAT",ios::in|ios::binary);
	if(!f_book)
	{
		cout<<"!!ERROR!!! FILE COULD NOT BE OPEN!!";
		getch();
		return;
	}
	cout<<"\n\n\t\t\t\tBOOK LIST\n\n";
	cout<<"===============================================================================\n";
	cout<<"BOOK NUMBER"<<setw(17)<<"BOOK NAME"<<setw(22)<<"AUTHOR"<<setw(25)<<"CATEGORY\n";
	cout<<"===============================================================================\n";
	while(f_book.read((char*)&b,sizeof(b)))
	{
		b.report();
	}
	f_book.close();
	getch();
}

/********************************************************************************************
FUNCTION TO DISPLAY ALL STUDENTS
*******************************************************************************************/

void read_student()
{
	clrscr();
	f_student.open("STUDENT.DAT",ios::in|ios::binary);
	if(!f_student)
	{
		cout<<"!!ERROR!!! FILE COULD NOT BE OPEN!!";
		getch();
		return;
	}
	cout<<"\n\n\t\t\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"\tADMISSION NUMBER"<<setw(15)<<"NAME"<<setw(20)<<"BOOKS ISSUED\n";
	cout<<"==================================================================\n";
	while(f_student.read((char*)&s,sizeof(s)))
	{
		s.report();
	}
	f_student.close();
	getch();
}

/**********************************************************************************************
FUNCTION TO SEARCH FOR A SPECIFIC BOOK FROM FILE
**********************************************************************************************/

void search_book()
{
	char n[50];
	cout<<"\n\n\t\t\t\tSEARCH BOOK RECORD\n\n";
	int flag=0;
	cout<<"\nENTER THE BOOK YOU WANT TO SEARCH: ";
	gets(n);
	f_book.open("BOOK.DAT",ios::in|ios::binary);
	if(!f_book)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_book.read((char*)&b,sizeof(b)))
	{
		if(!strcmpi(b.ret_bname(),n))
		{
			b.show_book();
			flag=1;
		}
	}
	f_book.close();
	if(flag==0)
	{
		cout<<"\n\n!!ERROR!!! BOOK RECORD NOT FOUND!!";
	}
	getch();
}

/*********************************************************************************************
FUNCTION TO SEARCH A SPECIFIC STUDENT FROM FILE
*********************************************************************************************/

void search_student()
{
	char n[6];
	cout<<"\n\n\t\t\t\tSEARCH STUDENT RECORD\n\n";
	int flag=0;
	cout<<"\nENTER ADMISSION NUMBER YOU WANT TO SEARCH: ";
	gets(n);
	f_student.open("STUDENT.DAT",ios::in|ios::binary);
	if(!f_student)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_student.read((char*)&s,sizeof(s)))
	{
		if(!strcmpi(s.retadmno(),n))
		{
			s.show_student();
			flag=1;
		}
	}
	f_student.close();
	if(flag==0)
	{
		cout<<"\n\n!!ERROR!!! STUDENT RECORD NOT FOUND!!";
	}
	getch();
}

/**********************************************************************************************
FUNCTION TO MODIFY BOOK
**********************************************************************************************/

void modify_book()
{
	char n[6];
	int found=0, pos;
	clrscr();
	cout<<"\n\n\t\t\t\tMODIFY BOOK RECORD\n\n";
	cout<<"\n\nENTER BOOK NUMBER YOU WANT TO MODIFY: ";
	gets(n);
	f_book.open("BOOK.DAT",ios::in|ios::out|ios::binary);
	if(!f_book)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_book.read((char*)&b,sizeof(b))&&found==0)
	{
		if(!strcmpi(b.retbno(),n))
		{
			b.show_book();
			cout<<"\nENTER NEW DETAILS: "<<endl<<endl;
			b.modify_book();
			pos=-1*sizeof(b);
			f_book.seekg(pos,ios::cur);
			f_book.write((char*)&b,sizeof(b));
			cout<<"\n\n!!RECORD UPDATED!!";
			found=1;
		}
	}
	f_book.close();
	if(found==0)
	{
		cout<<"\n\n!!ERROR!!! BOOK RECORD NOT FOUND!!";
	}
	getch();
}





/**********************************************************************************************
FUNCTION TO MODIFY STUDENT DETAILS
**********************************************************************************************/

void modify_student()
{
	char n[6];
	int found=0, pos;
	clrscr();
	cout<<"\n\n\t\t\t\tMODIFY STUDENT RECORD\n\n";
	cout<<"\n\nENTER THE ADMISSION NUMBER YOU WANT TO MODIFY: ";
	gets(n);
	f_student.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
	if(!f_student)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_student.read((char*)&s,sizeof(s))&&found==0)
	{
		if(!strcmpi(s.retadmno(),n))
		{
			s.show_student();
			cout<<"\n\nENTER NEW DETAILS: "<<endl<<endl;
			s.modify_student();
			pos=-1*sizeof(s);
			f_student.seekp(pos,ios::cur);
			f_student.write((char*)&s,sizeof(s));
			cout<<"\n\n!!RECORD UPDATED!!";
			found=1;
		}
	}
	f_student.close();
	if(found==0)
	{
		cout<<"\n\n!!ERROR!!! STUDENT RECORD NOT FOUND!! ";
	}
	getch();
}

/**********************************************************************************************
FUNCTION TO DELETE A BOOK RECORD
**********************************************************************************************/

void delete_book()
{
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\n\t\t\t\tDELETE BOOK RECORD\n\n";
	cout<<"\nENTER BOOK NUMBER YOU WANT TO DELETE: ";
	cin>>n;
	f_book.open("BOOK.DAT",ios::in|ios::out|ios::binary);
	fstream f_bookn;
	f_bookn.open("BOOK_NEW.DAT",ios::out|ios::binary);
	f_book.seekg(0,ios::beg);
	if(!f_book)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_book.read((char*)&b,sizeof(b)))
	{
		if(strcmpi(b.retbno(),n))
		{
			f_bookn.write((char*)&b,sizeof(b));
		}
		else
		{
			cout<<"\nDELETED BOOK RECORD: "<<endl<<endl;
			b.show_book();
			flag=1;
		}

	}
	if(flag==0)
	{
		cout<<"\n\n!!ERROR!!! BOOK RECORD NOT FOUND!!";
	}
	f_book.close();
	f_bookn.close();
	remove("BOOK.DAT");
	rename("BOOK_NEW.DAT","BOOK.DAT");
	cout<<"\n\n!!RECORD DELETED SUCCESSFULLY";
	getch();
}

/**********************************************************************************************
FUNCTION TO DELETE A STUDENT RECORD
**********************************************************************************************/

void delete_student()
{
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\n\t\t\t\tDELETE STUDENT RECORD\n\n";
	cout<<"\nENTER ADMISSION NUMBER YOU WANT TO DELETE: ";
	cin>>n;
	f_student.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
	fstream f_studentn;
	f_studentn.open("STUDENT_NEW.DAT",ios::out|ios::binary);
	f_student.seekg(0,ios::beg);
	if(!f_student)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_student.read((char*)&s,sizeof(s)))
	{
		if(strcmpi(s.retadmno(),n))
		{
			f_studentn.write((char*)&s,sizeof(s));
		}
		else
		{
			cout<<"\nDELETED DATA: "<<endl<<endl;
			s.show_student();
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\n\n!!ERROR!! STUDENT RECORD NOT FOUND!!";
	}
	f_student.close();
	f_studentn.close();
	remove("STUDENT.DAT");
	rename("STUDENT_NEW.DAT","STUDENT.DAT");
	getch();
}
/**********************************************************************************************
FUNCTION TO ISSUE BOOK
**********************************************************************************************/

void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0, pos;
	char ans,p;
	clrscr();
	cout<<"\n\n\t\tBOOK ISSUE\n\n";
	cout<<"\n\nENTER STUDENT ADMISSION NUMBER: ";
	cin>>sn;
	f_student.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
	f_book.open("BOOK.DAT",ios::in|ios::out|ios::binary);
	if(!f_student||!f_book)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_student.read((char*)&s,sizeof(s))&&found==0)
	{

		if(!strcmpi(s.retadmno(),sn))
		{
			found=1;
			if(s.rettoken()==0)
			{
				cout<<"\nDO YOU WANT TO SEE BOOK LIST? (Y/N): ";
				cin>>ans;
				if(ans=='y'||ans=='Y')
				{
					book b1;
					cout<<"\n\n\t\tBOOK LIST\n\n";
					cout<<"===============================================================================\n";
					cout<<"BOOK NUMBER"<<setw(17)<<"BOOK NAME"<<setw(22)<<"AUTHOR"<<setw(25)<<"CATEGORY\n";
					cout<<"===============================================================================\n";
					while(f_book.read((char*)&b1,sizeof(b1)))
					{
						b1.report();
					}
					f_book.close();
				}
				f_book.open("BOOK.DAT",ios::in|ios::out|ios::binary);
				cout<<"\n\nENTER BOOK NUMBER TO BE ISSUED: ";
				gets(bn);
				while(f_book.read((char*)&b,sizeof(b))&&flag==0)
				{
					if(!strcmpi(b.retbno(),bn))
					{
						b.show_book();
						flag=1;
						s.addtoken();
						s.getstbno(b.retbno());
						pos=-1*sizeof(s);
						f_student.seekp(pos,ios::cur);
						f_student.write((char*)&s,sizeof(s));
						cout<<"\n\nBOOK ISSUED SUCCESSFULLY";
						cout<<"\nWRITE ISSUE DATE AT THE BACK OF THE BOOK";
						cout<<"\nTHE BOOK MUST BE RETURNED WITHIN 15 DAYS OF ISSUE";
						cout<<"\nELSE A FINE OF Re.1 WILL BE CHARGED HENCEFORTH";
					}
				}
				if(flag==0)
					cout<<"!!ERROR!!! BOOK RECORD NOT FOUND!!";
			}
			else
				cout<<"PREVIOUS BOOK NOT RETURNED BY THE STUDENT";

		}
	}
	if(found==0)
	{
		cout<<"!!ERROR!!! STUDENT RECORD NOT FOUND";
	}
	getch();
	f_student.close();
	f_book.close();
}

/**********************************************************************************************
FUNCTION TO DEPOSIT BOOK
**********************************************************************************************/

void book_deposit()
{
	char sn[6],bn[6];
	int found=0,flag=0,day,fine, pos;
	clrscr();
	cout<<"\n\n\t\tBOOK DEPOSIT\n\n";
	cout<<"\n\nENTER STUDENT'S ADMISSION NUMBER: ";
	cin>>sn;
	f_student.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
	f_book.open("BOOK.DAT",ios::in|ios::out|ios::binary);
	if(!f_student||!f_book)
	{
		cout<<"\n!!ERROR!!! FILE NOT FOUND!!";
		getch();
		return;
	}
	while(f_student.read((char*)&s,sizeof(s))&&found==0)
	{
		if(!strcmpi(s.retadmno(),sn))
		{
			found=1;
			if(s.rettoken()==1)
			{
				while(f_book.read((char*)&b,sizeof(b))&&flag==0)
				{
					if(!strcmpi(b.retbno(),s.retstbno()))
					{
						b.show_book();
						flag=1;
						cout<<"\nENTER THE NUMBER OF DAYS FOR WHICH THE BOOK WAS ISSUED: ";
						cin>>day;
						if(day>15)
						{
							fine=(day-15)*1;
							cout<<"\n\nFINE TO BE DEPOSITED: Rs "<<fine;
						}
						s.resettoken();
						pos=-1*sizeof(s);
						f_student.seekp(pos,ios::cur);
						f_student.write((char*)&s,sizeof(s));
						cout<<"\n\nBOOK DEPOSITED SUCCESFULLY";
					}
				}
				if(flag==0)
				{
					cout<<"!!ERROR!!! BOOK RECORD NOT FOUND!!";
				}
			}
			else
			{
				cout<<"!!NO BOOK WAS ISSUED TO THIS STUDENT!!";
			}
		}
	}
	if(found==0)
	{
		cout<<"!!ERROR!!! STUDENT RECORD NOT FOUND!!";
	}
	getch();
	f_student.close();
	f_book.close();
	getch();
}

/**********************************************************************************************
END OF PROJECT
**********************************************************************************************/

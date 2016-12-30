#include <bits/stdc++.h>
#include "course.h"
#include"Student.h"
#include"Teacher.h"
#include"Doctor.h"
#include"TA.h"
#include"person.h"
#include"System.h"
using namespace std;
int main(){
	System fci(100);
	//-------------Making Two Objects Of Students , Teacher Assistant , Doctor
	//------------- Making 2 courses && Add Materials to them.
	Student s1("karim","1","karim2016@gmail.com","CS");
	fci.AllStudents[fci.NumOfS++]=&s1;
	Student s2("Ismail","2","ismail2016@gmail.com","IT");
	fci.AllStudents[fci.NumOfS++]=&s2;
	TA t1("Mohamed","3","mohamed2016@gmail.com","IS");
	fci.AllTAs[fci.NumOfT++]=&t1;
	TA t2("Rashad","4","rashad2016@gmail.com","DS");
	fci.AllTAs[fci.NumOfT++]=&t2;
	Doctor d1("Mahmoud","5","mahmoud2016@gmail.com","CS");
	d1.addCourse("Mahmoud","Math",&fci);
	d1.AddMaterial("http://www.math.com/",&fci);
	d1.AddMaterial("http://www.mathAllTimeIsFun.com/",&fci);
	fci.AllDoctors[fci.NumOfD++]=&d1;
	Doctor d2("Maged","6","maged2016@gmail.com","IT");
    Doctor d3("esss","6","maged2016@gmail.com","DS");
	d2.addCourse("Maged","English",&fci);
	d2.AddMaterial("http://www.Engliiiiish.com/",&fci);
	d2.AddMaterial("http://www.English.Ils.com/",&fci);
	fci.AllDoctors[fci.NumOfD++]=&d2;
	fci.AllDoctors[fci.NumOfD++]=&d3;
	///////////////////////////////////////////////////////////////////////////////////////
	Start :
    fci.Design();
    int x,ID;
    string pass,username;
    cin>>x;
    while(x!=2 && x!=1)
    {
    	cout<<"Please Reenter Your choice:  ";
    	cin>>x;
    }
    if(x==1)
    {
    	//---------Student---------Student---------Student---------Student---------Student---------Student-------
    	cout<<"Enter your UserName :   ";
    	cin>>username;
    	cout<<"Enter your Password   :   ";
    	cin>>pass;
    	for(int i=0 ; i<username.size() ; i++)
            if(isalpha(username[i]))
            {
                cout<<"Invalid user name Characters not allowed"<<endl;
                goto Start;
            }
        ID=fci.Int(username);
		system("cls") ;
    	if(ID>199999||ID<100000)	goto Start;
    	string Id=fci.NumberToString(ID);
		if(fci.SignIn(Id, pass))
		{
			Student *s;
			for(int i=0 ; i<fci.NumOfS ; i++)
				if(fci.AllStudents[i]->getId()==ID)
				{
					s=fci.AllStudents[i];
				}
			Student1:
			cout << "Choose from the following :"<<endl
				 << "1 . Join Course.\n"
				 << "2 . Get Materials\n"
				 << "3 . Show Grades\n"
				 << "4 . Log Out"<<endl;
			int t=0;
			while(t!=1 && t!=2 && t!=3 && t!=4)
			{
				cout<<"Enter Your Choice :  ";
				cin>>t;
				system("cls");
			}
			if(t==1)
			{
			    fci.ShowCourses();
			    cout<<endl<<endl;
				int v;
				cout<<"Enter Course ID which You want to join in :    ";
				cin>>v;
				system("cls");
				s->joinCourse(v,&fci);
				goto Student1;
			}
			else if(t==2)
			{
			    fci.ShowCourses();
			    cout<<endl<<endl;
				int v;
				cout<<"Whats Course ID You want to get Material :    ";
				cin>>v;
				system("cls");
				s->getMatrial(v);
				cout<<endl<<endl;
				goto Student1;
			}
			else if(t==3)
			{
				system("cls");
				s->ShowGrades();
				cout<<endl<<endl;
				goto Student1;
			}
			else
			{
				goto Start;
			}
		}
		else
		{
			goto Start;
		}
	}
	else
	{
		//-----------------------------------------------Stuff Log In-----------------------------------
    	cout<<"Enter UserName :   ";
    	cin>>username;
    	cout<<"Enter your Password   :   ";
    	cin>>pass;
    	for(int i=0 ; i<username.size() ; i++)
            if(isalpha(username[i]))
            {
                cout<<"Invalid user name Characters not allowed "<<endl;
                goto Start;
            }
        ID=fci.Int(username);
    	system("cls");
		if(ID<200000)	goto Start;
		else if(ID<300000)
		{
		//------------Teacher Assistant------------Teacher Assistant------------Teacher Assistant------------Teacher Assistant
    	string Id=fci.NumberToString(ID);
		if(fci.SignIn(Id, pass))
		{
				TA *ta;
				for(int i=0 ; i<fci.NumOfT ; i++)
					if(fci.AllTAs[i]->get_ID()==ID)
					{
						ta=fci.AllTAs[i];
					}
				TA1:
				cout << "Choose from the following :"<<endl
					 << "1 . Join Course.\n"
					 << "2 . Add Materials\n"
					 << "3 . Modify Grades\n"
					 << "4 . Log Out"<<endl;
				int t=0;
				while(t!=1 && t!=2 && t!=3 && t!=4)
				{
					cout<<"Enter Your Choice :   ";
					cin>>t;
					system("cls");
				}
				if(t==1)
				{
                    fci.ShowCourses();
                    cout<<endl<<endl;
					int v;
					cout<<"Enter Course ID Which You want to join in :    ";
					cin>>v;
					system("cls");
					ta->JoinCourse(v,&fci);
					goto TA1;
				}
				else if(t==2)
				{

					string v;
					cout<<"Enter The Course Materials you want to Add :    ";
					cin.sync();
					getline(cin,v);
					bool f = false;;
					for(int i = 0 ; i<v.length() ; ++i)
                    {
                        if(v[i] == ' ')
                        {
                            f = true;
                            break;
                        }
                    }
					try
					{
					    if(f == true)
                        {
                            throw "Material URL can't contain spaces.";
                        }
                        system("cls");
                        ta->AddMaterial(v,&fci);
                        goto TA1;
                    }
					catch(const char * x)
					{
					    cout << x << endl << endl << endl;
					}
					//system("cls");
					//ta->AddMaterial(v,&fci);
					goto TA1;
				}
				else if(t==3)
				{
					int v;
					cout<<"Enter The Student ID You want to Modify his Grades :    ";
					cin>>v;
					double g;
					cout<<"Enter His new Grade + Old Grades :    ";
					cin>>g;
					system("cls");
					ta->ModGrades(v,g,&fci);
					goto TA1;
				}
				else
				{
					goto Start;
				}
			}
			else
			{
				system("cls");
				goto Start;
			}
		}
		else
		{
		//----------Doctor----------Doctor----------Doctor----------Doctor----------Doctor----------Doctor---------
    	string Id=fci.NumberToString(ID);
		if(fci.SignIn(Id, pass))
			{
				Doctor *d;
				for(int i=0 ; i<fci.NumOfD ; i++)
					if(fci.AllDoctors[i]->GetID()==ID)
					{
						d=fci.AllDoctors[i];
					}
				Doctor1:
				cout << "Choose from the following :"<<endl
					 << "1 . Add Course.\n"
					 << "2 . Add Materials\n"
					 << "3 . Modify Grades\n"
					 << "4 . Log Out"<<endl;
				int t=0;
				while(t!=1 && t!=2 && t!=3 && t!=4)
				{
					cout<<"Enter Your Choice :   ";
					cin>>t;
					system("cls");
				}
				if(t==1)
				{
					string v1,v2;
					cout<<"What Course Name You want to Add :    ";
					cin.sync();
					getline(cin,v1);
					cout<<"Enter your Name :    ";
					cin.sync();
					getline(cin,v2);
					system("cls");
					d->addCourse(v2,v1,&fci);
					goto Doctor1;
				}
				else if(t==2)
				{
					string v;
					cout<<"Enter the Course Materials you want to Add :    ";
					cin.sync();
					getline(cin,v);
					bool f = false;;
					for(int i = 0 ; i<v.length() ; ++i)
                    {
                        if(v[i] == ' ')
                        {
                            f = true;
                            break;
                        }
                    }
					try
					{
					    if(f == true)
                        {
                            throw "Material URL can't contain spaces.";
                        }
                        system("cls");
                        d->AddMaterial(v,&fci);
                        goto Doctor1;
                    }
					catch(const char * x)
					{
					    cout << x << endl << endl << endl;
					}
					//system("cls");
					//d->AddMaterial(v,&fci);
					goto Doctor1;
				}
				else if(t==3)
				{
					int v;
					cout<<"Enter The Student ID You want to Modify his Grades :    ";
					cin>>v;
					double g;
					cout<<"Enter His new Grade + Old Grades :    ";
					cin>>g;
					system("cls");
					d->ModGrades(v,g,&fci);
					goto Doctor1;
				}
				else
				{
					system("cls");
					goto Start;
				}
			}
			else
			{
				goto Start;
			}
		}
	}
	system("cls") ;

}

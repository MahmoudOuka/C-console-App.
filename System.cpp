#include "System.h"
#include <iostream>
#include<fstream>
using namespace std ;
System::System()
{
    NumOfS=0;
    NumOfT=0,NumOfD=0;
    AllStudents=new Student*[100];
    AllTAs=new TA*[100];
    AllDoctors=new Doctor*[100];
}
System::System(int num)
{
    NumOfS=0;
    NumOfT=0,NumOfD=0;
	AllStudents=new Student*[num];
    AllTAs=new TA*[num];
    AllDoctors=new Doctor*[num];
}
void System::Design()
{
	cout<<"= ================================ ="<<endl;
	cout<<"="<<setw(35)<<"="<<endl<<"="<<setw(35)<<"="<<endl<<"="<<setw(35)<<"="<<endl;
	cout<<"="<<"          1- Student Log In"<<setw(8)<<"="<<endl;
	cout<<"="<<"          2- Stuff Log In"<<setw(10)<<"="<<endl;
	cout<<"="<<setw(35)<<"="<<endl<<"="<<setw(35)<<"="<<endl<<"="<<setw(35)<<"="<<endl;
	cout<<"= ================================ ="<<endl;
}
// int to string
string System::NumberToString ( int Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}
int System::Int(string s)
{
	int t=0;
	istringstream (s)>>t;
	return t;
}
bool System::SignIn (string UserName, string Password)
{
	ifstream readFile("ids.txt");
	string line=" ";
	bool found = false;
	string _UserName;
	string _Password;
	while (getline(readFile,line))
	{
   		 stringstream iss(line);
  	  iss >> _UserName >> _Password;

  		if (UserName == _UserName && Password == _Password)
		{
       	 	cout << "Successfully login!"<< endl<<endl<<endl;
       		 found = true;
       		 break;
    	}
	}

	if (!found) {
   		 cout << "Invalid UserName OR Password"<< endl<<endl<<endl;
	}
	return found;
}
void System:: ShowCourses()
{
    for(int i=0 ; i<AllCourses.size() ; i++)
    {
        cout<<AllCourses[i].getCourseName()<<"  "<<AllCourses[i].getCourseID()<<endl;
    }
}
System::~System()
{
// 	delete [] AllStudents ;
//    delete [] AllTAs ;
//    delete [] AllDoctors ;
}


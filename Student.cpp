#include <bits/stdc++.h>
#include<string>
#include "Student.h"
static int i=100000;
using namespace std ;

Student::Student(string n, string ps , string m , string dp):Person(n,ps,m,dp)
{
    SID=i++;
    courses=new Course*[6];
    num=0;
}
Student::Student() {};
void Student::setname(string n)
{
    Name = n ;
}
void Student::setmail(string n)
{
    Mail = n ;
}
void Student::setpassword(string n)
{
    Password = n ;
}
void Student::setdepartment(string n)
{
    Dep = n ;
}
string Student::getname()
{
    return Name ;
}
string Student::getmail()
{
    return Mail ;
}
string Student::getpassword()
{
    return Password ;
}
string Student::getdepartment()
{
    return Dep ;
}
int Student::getId()
{
    return SID ;
}
void Student::getMatrial(int CourseId)
{
    bool m=false;
    for(int i = 0 ; i < num ; i++)
    {
        if(courses[i]->getCourseID() == CourseId)
        {
            m=true;
            courses[i]->getM();
        }
    }
    if(!m) cout << "You are not registered to this course.\n"<<endl<<endl<<endl;
}
void Student::joinCourse(int courseID,System *s)
{
	bool M=false;
	for(int i=0 ; i<CourseGrade.size() ; i++)
	{
		if(CourseGrade[i].first.getCourseID()==courseID)
		{
			cout<<"You Have already Registered in this Course"<<endl<<endl<<endl;
			return;
		}
	}
    for(int i = 0 ; i < s->AllCourses.size() ; i++)
    {
        if(s->AllCourses[i].getCourseID()==courseID)
        {
        	M=true;
            s->AllCourses[i].JoinStudents(this);
            courses[num++]=&s->AllCourses[i];
            CourseGrade.push_back(make_pair(s->AllCourses[i],0.0));
            cout<<"join Successfully!"<<endl<<endl<<endl;
        }
    }
    if(!M)	cout<<"it is wrong course ID"<<endl<<endl<<endl;
}
Student Student::operator=(Student &s)
{
    SID=s.SID;
    NumOfStudent=s.NumOfStudent;
    Level=s.Level;
    num=s.num;
    //delete [] courses;
    courses=new Course*[6];
    for(int i = 0 ; i < num ; i++ )
    {
        courses[i]=s.courses[i];
    }
    for(int i = 0 ; i < CourseGrade.size() ; i++ )
    {
        CourseGrade[i].first = s.CourseGrade[i].first;
        CourseGrade[i].second = s.CourseGrade[i].second;
    }
    return *this;
}
Student::Student(Student &s)
{
    SID=s.SID;
    NumOfStudent=s.NumOfStudent;
    Level=s.Level;
    num=s.num;
    courses=new Course*[6];
    for(int i = 0 ; i < num ; i++ )
    {
        courses[i]=s.courses[i];
    }
    for(int i = 0 ; i < CourseGrade.size() ; i++ )
    {
        CourseGrade[i].first = s.CourseGrade[i].first;
        CourseGrade[i].second = s.CourseGrade[i].second;
    }
}
void Student::ShowGrades()
{
	for(int i=0 ; i<CourseGrade.size() ; i++)
	{
		cout<<CourseGrade[i].first.getCourseName()<<" "<<CourseGrade[i].second<<endl;
	}
}
//Student::~Student()
//{
//    //delete [] courses;
//}

#include <bits/stdc++.h>
using namespace std;
#include "TA.h"
#include "Student.h"
TA::TA() {};
TA::TA(string n, string ps , string m , string dp):Person( n,  ps ,  m ,  dp)
{
    static int id=200000;
    TAID=id++;
    courseID=-1;
}
int TA ::getcourseID()
{
    return courseID;
}
int TA::get_ID()
{
	return TAID;
}
void TA :: JoinCourse(int CourseID ,System *s)
{
    if(courseID!=-1)
        cout<<"you have already registered in another course"<<endl<<endl<<endl;
    else
    for(int i=0; i<s->AllCourses.size(); i++)
    {
        if(s->AllCourses[i].getCourseID()==CourseID)
        {
            s->AllCourses[i].joinTA(TAID);
            courseID=CourseID;
            cout<<"join Successfully!"<<endl<<endl<<endl;
            break;
        }
        //courseID=CourseID;
    }
}
TA::TA(const TA&D)
{
	courseID=D.courseID;
	TAID=D.TAID;
    Name=D.Name;
    Password=D.Password;
    Mail=D.Mail;
    Dep=D.Dep;
}
void TA::operator=(const TA &D )
{
    courseID=D.courseID;
    TAID=D.TAID;
    Name=D.Name;
    Password=D.Password;
    Mail=D.Mail;
    Dep=D.Dep;
}
void TA::AddMaterial(string s,System *f)
{
    bool M=false;
	if(courseID==-1)	cout<<"you are not registered in any course"<<endl<<endl<<endl;
	else
	{
 	   for(int i=0 ; i<f->AllCourses.size(); i++)
   	 {
   	     if(f->AllCourses[i].getCourseID()==courseID)
   	     {
   	         M=true;
   	         f->AllCourses[i].AddM(s);
   	         cout<<"The Material is Added Successfully!"<<endl<<endl<<endl<<endl;
   	     }
   	 }
    if(!M)	cout<<"You Are not allowed to add materials to this course "<<endl<<endl<<endl;
	}
}
void TA :: ModGrades(int studentID, double grade, System *s)
{
    bool M=false,N=false;
    for(int i = 0 ; i<s->NumOfS ; ++i)
    {
        if(s->AllStudents[i]->getId()==studentID)
        {
            M=true;
            for(int j=0 ; j<s->AllStudents[i]->CourseGrade.size(); j++)
            {
                if(s->AllStudents[i]->CourseGrade[j].first.getCourseID()==courseID)
                {
                    N=true;
                    s->AllStudents[i]->CourseGrade[j].second=grade;
                    cout<<"The Grade Changed Successfully!"<<endl<<endl<<endl;
                }
            }
        }
    }
    if(!N)  cout<<"This Student is not Registered in this Course"<<endl<<endl<<endl;
    if(!M)  cout<<"Invalid Student ID"<<endl<<endl<<endl;
}

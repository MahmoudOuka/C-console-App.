#include <bits/stdc++.h>
#include "Doctor.h"
#include"Course.h"
#include"Student.h"
Doctor::Doctor() {}

Doctor ::Doctor ( string n, string ps, string m, string dp):Person(n,ps,m,dp)
{
	static int i = 300000 ;
    DrID = i++;
    CourseID=-1;
}
void Doctor :: addCourse(string drName, string courseName,System  *s)
{
    if(CourseID!=-1)    cout<<"You have already had another a course"<<endl;
    else
    {
        Course c(drName, courseName);
        s->AllCourses.push_back(c);
        cout<<courseName<<" ID is : " <<c.getCourseID()<< "\n" ;
        CourseID=c.getCourseID();
    }
}
void Doctor :: operator=(const Doctor &d)
{
	Name = d.Name;
	Mail = d.Mail;
	Dep = d.Dep;
	Password = d.Password;
	DrID = d.DrID;
	CourseID = d.CourseID;
}

Doctor :: Doctor(const Doctor &d)
{
	Name = d.Name;
	Mail = d.Mail;
	Dep = d.Dep;
	Password = d.Password;
	DrID = d.DrID;
	CourseID = d.CourseID;
	}
int Doctor::GetID()	{return DrID;}
void Doctor :: ModGrades(int studentID, double grade,System *s)
{
    bool M=false,N=false;
    for(int i = 0 ; i<s->NumOfS ; ++i)
    {
        if(s->AllStudents[i]->getId()==studentID)
        {
            M=true;
            for(int j=0 ; j<s->AllStudents[i]->CourseGrade.size(); j++)
            {
                if(s->AllStudents[i]->CourseGrade[j].first.getCourseID()==CourseID)
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

void Doctor::  AddMaterial(string s,System *f)
{
	 bool M=false;
	if(CourseID==-1)	cout<<"you are not registered in eny course"<<endl<<endl<<endl<<endl;
   else
   {
    for(int i=0 ; i<f->AllCourses.size(); i++)
    {
        if(f->AllCourses[i].getCourseID()==CourseID)
        {
            M=true;
            f->AllCourses[i].AddM(s);
            //cout<<"The Material is Added Successfully!"<<endl<<endl<<endl<<endl;
        }
    }
    if(!M)	cout<<"You Are not allowed to add materials to this course "<<endl;
	}
}

Doctor :: ~Doctor()
{

}


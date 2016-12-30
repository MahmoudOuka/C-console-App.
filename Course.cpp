#include "Course.h"
#include "Student.h"
#include<string>
static int id=1,k=0;
Course::Course(string name1,string name2)
{
    DoctorName=name1;
    CourseName=name2;
    CourseID=id++;
    NumOfStudent=0;
    Students=new Student*[1000];
}
Course::Course()
{
    DoctorName=" ";
    CourseName=" ";
    CourseID=id++;
    NumOfStudent=0;
    Students=new Student*[1000];
}
void Course::setCourseName(string s)
{
    CourseName=s;
}
string Course::getCourseName()
{
    return CourseName;
}
int Course::getCourseID()
{
    return CourseID;
}
void Course::JoinStudents(Student * s)
{
	Students[NumOfStudent]=s;
}
void Course::AddM(string s)
{
    Materials.push_back(s);
}
int Course::joinTA(int id)
{
    TAsID.push_back(id);
}
void Course :: getM()
{
    cout<<"This Course Materials Are : "<<endl;
    for(int i=0 ; i<Materials.size() ; i++)
    {
        cout<<Materials[i]<<endl;
    }
}
Course::~Course()
{
    //delete [] Students;
}


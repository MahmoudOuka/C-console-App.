#ifndef STUDENT_H
#define STUDENT_H
#include <bits/stdc++.h>
#include"course.h"
#include"Person.h"
using namespace std ;

class Student : public Person
{
public:
    vector < pair < Course , double > > CourseGrade;

    //vector < Course > CourseGrade;
    Student(string n, string ps , string m , string dp);
    Student();
    void getMatrial(int CourseId);
	void joinCourse(int courseID,System *s);
    void setname(string n);
    void setmail(string n);
    void setpassword(string n);
    void setdepartment(string n);
    void setId(int n);
    string getname();
    int getId();
    string getmail();
    string getpassword();
    string getdepartment();
	void ShowGrades();
	Student operator=(Student &s);
	Student(Student &s);
    //~Student();

protected:
    Course ** courses;
    int SID,NumOfStudent;
    int Level;
    int num;

};

#endif // STUDENT_H

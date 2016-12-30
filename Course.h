#include <bits/stdc++.h>
using namespace std;
#ifndef COURSE_H
#define COURSE_H

class Student;
class TA;
class Doctor;
class Course
{
protected:
    string CourseName, DoctorName;
    vector<string>Materials;
    int CourseID , NumOfStudent ;
    Student ** Students;
    vector<int>TAsID;
public:
    Course(string name1,string name2);
    Course();
    ~Course();
    void setCourseName(string s);
    string getCourseName();
    int getCourseID();
    void JoinStudents(Student * s);
    void getM();
    void AddM(string s);
    int joinTA(int id);
};

#endif


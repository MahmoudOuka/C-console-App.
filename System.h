#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <bits/stdc++.h>
#include"Course.h"
using namespace std ;
class Person;
class System
{
public:
    System();
    ~System();
    Student ** AllStudents ;
    TA ** AllTAs ;
    Doctor ** AllDoctors ;
    int NumOfS,NumOfT,NumOfD;
    string NumberToString(int Number);
    vector <Course> AllCourses ;
    void Design();
    System(int num);
    bool SignIn (string,string) ;
    int Int(string s);
    void ShowCourses();
protected:
	    int id ;
        string pass ;


};

#endif // SYSTEM_H

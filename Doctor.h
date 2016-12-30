#ifndef DOCTOR_H
#define DOCTOR_H

#include <bits/stdc++.h>
#include "Person.h"
#include "Teacher.h"

using namespace std;

class Doctor : public Person, public Teacher
{
public:
    Doctor();
    Doctor ( string n, string ps, string m, string dp);
    void addCourse(string courseName, string drName ,System * s);
    void ModGrades(int studentID, double grade,System *s);
    void  AddMaterial(string s,System *f);
	void  operator=(const Doctor &d);
	Doctor(const Doctor &d);
    int GetID();
    ~Doctor();
protected:
    int DrID;
    int CourseID;
    //vector<pair<Course,double> >CourseGrade;

};

#endif // DOCTOR_H

#ifndef TA_H_INCLUDED
#define TA_H_INCLUDED
#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Course.h"

class TA :public Teacher , public Person
{
protected :

    int courseID;
    int TAID;
public :
    TA();
    TA(string n, string ps , string m , string dp);
    void JoinCourse(int courseID, System *s);
    int getcourseID();
    int get_ID();
    void ModGrades(int studentID, double grade,System *s);
    void AddMaterial(string s,System *f);
    TA(const TA&D);
    void operator=(const TA &D );
};
#endif // TA_H_INCLUDED

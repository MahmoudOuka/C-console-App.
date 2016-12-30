#ifndef SUMMER_H
#define SUMMER_H
#include "Doctor.h"
#include"Course.h"
#include"Student.h"
#include "TA.h"
#include<bits/stdc++.h>

using namespace std;

template <class T>
class Summer
{
    public:
        Summer();
        void Addcourse(Course *c,int siz);
        void Addstudent(Student *s,int siz);
        void AddTAS(TA *t,int siz);
        void AddDoctor(Doctor *d,int siz);
        ~Summer();
    protected:
        Doctor **Doctors;
        Student **Students;
        TA **TAS;
        Course **Courses;
        T size_C , size_S ,size_D ,size_T ;
};

#endif // SUMMER_H

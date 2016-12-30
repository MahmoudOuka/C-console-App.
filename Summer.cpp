#include "Summer.h"
#include <bits/stdc++.h>

using namespace std;
template <class T>
Summer<T>::Summer()
{
    size_C=0;
    size_D=0;
    size_S=0;
    size_T=0;
}
template <class T>
void Summer<T>::Addcourse(Course *c, int siz)
{
    if(size_C==0)
    {
        size_C+=siz;
        Courses = new Course*[siz];
        Courses[0]= c;
    }
    if(size_C > 0)
    {
        size_C+=siz;
        Course ** c1= new Course*[siz];
        for(int i = 0 ; i < size_C ; i++)
        {
            c1[i]=Courses[i];
        }
        delete []Courses;
        Courses = c1;
        Courses[size_C-1] = c;
    }
}
template <class T>
void Summer<T>::Addstudent(Student *s,int siz)
{
    if(size_S==0)
    {
        size_S+=siz;
        Students = new Student*[siz];
        Students[0]= s;
    }
    if(size_S > 0)
    {
        size_S+=siz;
        Student ** c1= new Student*[siz];
        for(int i = 0 ; i < size_S ; i++)
        {
            c1[i]=Students[i];
        }
        delete []Students;
        Students = c1;
        Students[size_S-1] = s;
    }
}
template <class T>
void Summer<T>::AddTAS(TA *t ,int siz)
{
    if(size_T == 0)
    {
        size_T+=siz;
        TAS = new TA*[siz];
        TAS[0] = t;
    }
    if(size_T > 0)
    {
        size_T+=siz;
        TA ** c1= new TA*[siz];
        for(int i = 0 ; i < size_T ; i++)
        {
            c1[i]=TAS[i];
        }
        delete []TAS;
        TAS = c1;
        TAS[size_T-1] = t;
    }
}
template <class T>
void Summer<T>:: AddDoctor(Doctor *d , int siz=3)
{
    if(size_D==0)
    {
        size_D+=siz;
        Doctors = new Doctor*[siz];
        Doctors[0]=d;
    }
    if(size_D > 0)
    {
        size_D+=siz;
        Doctor ** c1= new Doctor*[siz];
        for(int i = 0 ; i < size_D ; i++)
        {
            c1[i]=Doctors[i];
        }
        delete []Doctors;
        Doctors = c1;
        Doctors[size_D-1] = d;
    }
}
template <class T>
Summer<T>::~Summer()
{
        delete [] Doctors;
        delete []Students;
        delete []TAS;
        delete []Courses;
}

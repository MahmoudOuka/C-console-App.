#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include<bits/stdc++.h>
#include"System.h"
using namespace std;

class Teacher
{
	public:
   	 	virtual void AddMaterial (string s,System *f)=0;
   	 	virtual void ModGrades(int studentid , double newgrade,System *s)=0;
   	 	//Teacher();
};

#endif // TEACHER_H_INCLUDED

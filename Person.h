#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include "System.h"
using namespace std ;

class Person : public System
{
protected:
    string Name , Mail , Dep, Password ;
public :
    Person();
    Person(string n, string ps , string m ,string dp);
};

#endif // PERSON_H

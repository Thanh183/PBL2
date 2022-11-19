#include "Book.h"
#include "Date.h"
#include<iostream>
#pragma once
using namespace std;
class User
{
private:
    string name;
    int age;
    string ID;
    string phonenumber;
    string address;
    Book *ab;
    int numBl;
public:
    
    //User();
    User(string="", string="", int=0, string="", string="");
    string getID();
    void setID(string ID);
    string getname();
    void setname(string name);
    int getage();
    void setage(int age);
    string getphonenumber();
    void setphonenumber(string phonenumber);
    string getaddress();
    void setaddress(string address);
    int getnumBl();
    void setnumBl(int);
    friend class Funu;
    ~User();
};  
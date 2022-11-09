#include "User.h"
using namespace std;
User::User()
{
    this-> ID= "Ma thu vien";
    this-> name="Ten";
    this-> age=0;
    this-> phonenumber="So dien thoai";
    this-> address="Dia chi";
}

User::User( string ID, string name, int age, string phonenumber, string address )
{
    this-> ID=ID;
    this-> name=name;
    this-> age=age;
    this-> phonenumber=phonenumber;
    this-> address=address;
}
string User::getID()
{
    return this->ID;
}
void User::setID(string ID)
{
    this->ID=ID;
}
string User::getname()
{
    return this-> name;
}
void User::setname(string name)
{
    this->name=name;
}
int User::getage()
{
    return this->age;
}
void User::setage(int age)
{
    this->age=age;
}
string User::getphonenumber()
{
    return this->phonenumber;
}
void User::setphonenumber(string phonenumber)
{
    this->phonenumber=phonenumber;
}
string User::getaddress()
{
    return this->address;
}
void User::setaddress(string address)
{
    this->address=address;
}
User::~User(){}
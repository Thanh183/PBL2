#include "User.h"

User::User( string name, int age, int ID, int phoneNumber, string address )
{
    this-> name=name;
    this-> age=age;
    this-> ID=ID;
    this-> phoneNumber=phoneNumber;
    this-> address=address;
}
string User:: getname()
{
    return this-> name;
}
void User:: setname(string name)
{
    this->name=name;
}
int User:: getage()
{
    return this->age;
}
void User:: setage(int age)
{
    this->age=age;
}
int User:: getID()
{
    return this->ID;
}
void User:: setID(int ID)
{
    this->ID=ID;
}
int User:: getphoneNumber()
{
    return this->phoneNumber;
}
void User:: setphoneNumber(int phoneNumber)
{
    this->phoneNumber=phoneNumber;
}
string User:: getaddress()
{
    return this->address;
}
void User:: setaddress(string address)
{
    this->address=address;
}
User::~User(){}
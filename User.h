#include <iostream>
using namespace std;
#pragma once
class User
{
private:
    string name;
    int age;
    int ID;
    int phoneNumber;
    string address;
public:
    User(string, int, int, int, string);
    string getname();
    void setname(string name);
    int getage();
    void setage(int age);
    int getID();
    void setID(int ID);
    int getphoneNumber();
    void setphoneNumber(int phoneNumber);
    string getaddress();
    void setaddress(string address);
    ~User();
};  
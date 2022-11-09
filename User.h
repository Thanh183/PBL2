#include<iostream>
using namespace std;
class User
{
private:
    string name;
    int age;
    string ID;
    string phonenumber;
    string address;
public:
    static int numUser;
    User();
    User(string, string, int, string, string);
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
    ~User();
};  
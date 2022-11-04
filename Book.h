#include <iostream>
using namespace std;
#pragma once
class Book
{
private:
    string name;
    string numCode;
    string category;
    int quantity;
    string author;
    string publisher;
    int status;
public:
    static int numBook;
    Book();
    Book(string, string, string, int, string, string, int);
    string getname();
    void setname(string name);
    string getnumCode();
    void setnumCode(string numCode);
    string getcategory();
    void setcategory(string category);
    int getquantity();
    void setquantity(int quantity);
    string getauthor();
    void setauthor(string author);
    string getpublisher();
    void setpublisher(string publisher);
    int getstatus();
    void setstatus(int status);
    ~Book();
};  
#include <iostream>
using namespace std;
#pragma once
class Book
{
private:
    string title;
    string numCode;
    string category;
    string author;
    string publisher;
public:
    // Book();
    Book(string="", string="", string="", string="", string="");
    string gettitle();
    void settitle(string);
    string getnumCode();
    void setnumCode(string);
    string getcategory();
    void setcategory(string);
    string getauthor();
    void setauthor(string);
    string getpublisher();
    void setpublisher(string);
    ~Book();
};  
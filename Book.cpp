#include"Book.h"
Book:: Book()
{
    this->name="Ten sach";
    this->numCode="Ma sach";
    this->category="Loai sach";
    this->quantity=0;
    this->author="Tac gia";
    this->publisher="Nxb";
    this->status=0;

}
Book:: Book(string name, string numCode, string category, int quantity, string author, string publisher,int status)
{
    this->name=name;
    this->numCode=numCode;
    this->category=category;
    this->quantity=quantity;
    this->author=author;
    this->publisher=publisher;
    this->status=status;
}
string Book:: getname()
{
    return this->name;
}
void Book:: setname(string name)
{
    this->name=name;
}
string Book:: getnumCode()
{
    return this->numCode;
}
void Book:: setnumCode(string numCode)
{
    this->numCode=numCode;
}
string Book:: getcategory()
{
    return this->category;
}
void Book:: setcategory(string category)
{
    this->category=category;
}
int Book:: getquantity()
{
    return this->quantity;
}
void Book:: setquantity(int quantity)
{   
    this->quantity=quantity;
}
string Book:: getauthor()
{
    return this->author;
}
void Book:: setauthor(string author)
{
    this->author=author;
}
string Book::getpublisher()
{
    return this->publisher;
}
void Book::setpublisher(string publisher)
{
    this->publisher=publisher;
}
int Book::getstatus()
{
    return this->status;
}
void Book::setstatus(int status)
{
    this->status=status;
}
Book::~Book(){
    
}
//git config --global user.email "you@example.com"
//  git config --global user.name "Your Name"
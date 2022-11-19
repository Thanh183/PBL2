#include"Book.h"
// Book:: Book()
// {
//     this->name="Ten sach";
//     this->numCode="Ma sach";
//     this->category="Loai sach";
//     this->author="Tac gia";
//     this->publisher="Nxb";
// }
Book::Book(string name, string numCode, string category, string author, string publisher)
{
    this->title=name;
    this->numCode=numCode;
    this->category=category;
    this->author=author;
    this->publisher=publisher;
}
string Book:: gettitle()
{
    return this->title;
}
void Book:: settitle(string name)
{
    this->title=name;
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
Book::~Book(){
    
}
//git config --global user.email "you@example.com"
//  git config --global user.name "Your Name"
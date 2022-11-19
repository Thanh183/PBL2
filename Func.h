#include "Book.h"
#pragma once
class Func
{
private:
    Book *b;
    int numBook;
public:
    Func(int=0);
    ~Func();
    int getnumBook();
    void setnumBook(int);
    void readBook();                //doc du lieu tu file
    void showAll();                 //in ra mh tat ca sach
    void addBook();                 //them sach vao cuoi
    void insertBook(int);           //them sach vao vi tri bat ki
    void removeBook();              //xoa sach theo ma sach
    void updateBook();              //chinh sua sach
    friend class Funu;
};


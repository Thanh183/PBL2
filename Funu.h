#include "User.h"
#include "Func.h"
#include <iostream>
using namespace std;
#pragma once
class Funu
{
private:
    User *s;
    int numUser;
public:
    Funu(int=0) ;
    ~Funu();
    int getnumUser();
    void setnumUser(int);
    void readUser();                //doc du lieu tu file
    void showUser();                 //in ra mh tat ca user
    void addUser();                 //them user vao cuoi
    void insertUser(int);           //them user vao vi tri bat ki
    void removeUser();              //xoa user theo ma sach
    void updateUser();
    //friend class User;
    void readMS();
    void showMS();
    void addBl(int k,Book);
    void borrowB();
    void returnB();
};
#include "Book.h"
#include "User.h"

class Func
{
private:
    Book *b;
    User *s;
    int numBook;
    int numUser;
public:
    Func(int=0,int=0);
    ~Func();
    int getnumBook();
    void setnumBook(int);
    void readBook();                //doc du lieu tu file
    void showAll();                 //in ra mh tat ca sach
    void addBook();                 //them sach vao cuoi
    void insertBook(int);           //them sach vao vi tri bat ki
    void removeBook();              //xoa sach theo ma sach
    void updateBook();              //chinh sua sach
};


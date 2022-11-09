#include "User.h"

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
    void showUser();                 //in ra mh tat ca sach
    void addUser();                 //them sach vao cuoi
    void insertUser(int);           //them sach vao vi tri bat ki
    void removeUser();              //xoa sach theo ma sach
    void updateUser();
};
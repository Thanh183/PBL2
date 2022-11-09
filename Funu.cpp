#include<fstream>
#include<cstdlib>
#include "Funu.h"

Funu::Funu(int numUser)
{   
    this->s=0;
    this->numUser=0;
}
Funu::~Funu(){};
int Funu::getnumUser()
{
    return this->numUser;
}
void Funu::setnumUser(int numUser)
{
    this->numUser=numUser;
}
void Funu::readUser()
{   
    ifstream readfile("User.txt");
    while(! readfile.eof())
    {
        User temp;
        string ID;
        getline(readfile,ID,',');
        temp.setID(ID);
        string name;
        getline(readfile,name,',');
        temp.setname(name);
        string age;
        getline(readfile,age,',');
        temp.setage(atoi(age.c_str()));
        string phonenumber;
        getline(readfile,phonenumber,',');
        temp.setphonenumber(phonenumber);
        string address;
        getline(readfile,address);
        temp.setaddress(address);
        if(this->numUser == 0)
        {   
            this->s=new User[this->numUser+1];
            *(this->s +this->numUser)=temp;
        }
        else
        {
            User* q=new User[this->numUser];
            for(int i=0;i<this->numUser;i++)
            {
                *(q+i)=*(this->s+i);
            }
            delete[] this->s;
            this->s=new User[this->numUser+1];
            for(int i=0;i<this->numUser;i++)
            {
                *(this->s+i)=*(q+i);
            }
            *(this->s +this->numUser)=temp;
            delete[] q;
        }
    ++this->numUser;
    }
    readfile.close();
    cout<<"Doc du lieu thanh cong!"<<endl;
}
void Funu::showUser()
{
    for(int i=0;i<this->numUser;i++)
    {
        cout<<(this->s+i)->getID()<<", ";
        cout<<(this->s+i)->getname()<<", ";
        cout<<(this->s+i)->getage()<<", ";
        cout<<(this->s+i)->getphonenumber()<<", ";
        cout<<(this->s+i)->getaddress()<<endl;
    }
}
void Funu::addUser()
{      
    showUser();
    ofstream addfile("User.txt", ios::out| ios::app);
    User temp;
    string u;
    int numuser;
    addfile<<endl;
    cout<<"Nhap ID: ";
    getline(cin,u);
    temp.setID(u);
    addfile<<temp.getID();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap ten sinh vien: ";
    getline(cin,u);
    temp.setname(u);
    addfile<<temp.getname();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap tuoi: ";
    cin>>numuser;
    temp.setage(numuser);
    addfile<<temp.getage();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap so dien thoai: ";
    getline(cin,u);
    temp.setphonenumber(u);
    addfile<<temp.getphonenumber();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap dia chi: ";
    getline(cin,u);
    temp.setaddress(u);
    addfile<<temp.getaddress();
    if(this->numUser == 0)
    {   
        this->s=new User[this->numUser+1];
        *(this->s +this->numUser)=temp;
    }
    else
    {
        User* q=new User[this->numUser];
        for(int i=0;i<this->numUser;i++)
        {
            *(q+i)=*(this->s+i);
        }
        delete[] this->s;
        this->s=new User[this->numUser+1];
        for(int i=0;i<this->numUser;i++)
        {
            *(this->s+i)=*(q+i);
        }
        *(this->s +this->numUser)=temp;
        delete[] q;
    }
    ++this->numUser;
    addfile.close();
}
void Funu::insertUser(int index)
{   
    showUser();
    ofstream addfile("User.txt", ios::out| ios::trunc);
    User temp;
    string ID;
    string name;
    int age;
    string phonenumber;
    string address;
    cout<<"Nhap ID: ";
    getline(cin,ID);
    temp.setID(ID);
    fflush(stdin);
    cout<<"Nhap ten sinh vien: ";
    getline(cin,name);
    temp.setname(name);
    fflush(stdin);
    cout<<"Nhap tuoi: ";
    cin>>age;
    temp.setage(age);
    fflush(stdin);
    cout<<"Nhap so dien thoai: ";
    getline(cin,phonenumber);
    temp.setphonenumber(phonenumber);
    fflush(stdin);
    cout<<"Nhap dia chi: ";
    getline(cin,address);
    temp.setaddress(address);
    User *q=new User[this->numUser];
    for(int i=0;i<this->numUser;i++)
    {
        *(q+i)=*(this->s+i);
    }
    delete[] this->s;
    this->s=new User[this->numUser+1];
    for(int i=0;i<this->numUser;i++)
    {   
        *(this->s+i)=*(q+i);
    }
    for(int i=index+1;i<=this->numUser;i++)
    {
        *(this->s+i)=*(this->s+i-1);
    }
    *(this->s+index)=temp;
    delete[] q;
    ++this->numUser;
    for(int i=0;i<this->numUser;i++)
    {
        addfile<<(this->s+i)->getID()<<",";
        addfile<<(this->s+i)->getname()<<",";
        addfile<<(this->s+i)->getage()<<",";
        addfile<<(this->s+i)->getphonenumber()<<",";
        addfile<<(this->s+i)->getaddress();
        if(i<this->numUser-1) addfile<<endl;
    }
    addfile.close();
}
void Funu::removeUser()
{   
    showUser();
    string temp;
    cout<<"Nhap ID muon xoa: ";
    getline(cin,temp);
    int k;
    for(int i=0;i<this->numUser;i++)
    {
        if((this->s+i)->getID() == temp) 
            {   
                k=i;
                break;
            }
        if(i==this->numUser-1) cout<<"Khong ton tai!";
    }
    if(this->numUser >= 0)
    {
        if(this->numUser == 1) 
        {
            delete[] this->s;
            this->numUser=0;
        }
        else
        {
            User *p=new User[this->numUser];
            for(int i=0;i<this->numUser;i++)
            {
                *(p+i)=*(this->s +i);
            }
            delete[] this->s;
            this->s=new User[this->numUser-1];
            for(int i=0;i<this->numUser-1;i++)
            {
                if(i<k)
                    *(this->s+i)=*(p+i);
                else *(this->s+i)=*(p+i+1);
            }   
            delete[] p;
        }
        this->numUser--;
    }
    ofstream addfile("User.txt", ios::out| ios::trunc);
    for(int i=0;i<this->numUser;i++)
    {
        addfile<<(this->s+i)->getID()<<",";
        addfile<<(this->s+i)->getname()<<",";
        addfile<<(this->s+i)->getage()<<",";
        addfile<<(this->s+i)->getphonenumber()<<",";
        addfile<<(this->s+i)->getaddress();
        if(i<this->numUser-1) addfile<<endl;
    }
    addfile.close();
}
void Funu::updateUser()
{
    showUser();
    int select=0;
    do
    {   
        int k=0;
        string temp;
        cout<<"Chon ID can sua :";
        fflush(stdin);
        getline(cin,temp);
        for(int i=0;i<this->numUser;i++)
        {
            if((this->s+i)->getID() == temp)
            {
                k=i;
                break;
            }
            if(i==this->numUser-1) cout<<"Khong ton tai!";
        }
        cout<<"Chon so tu 1 den 7 sua:"<<endl;
        cout<<"1.ID"<<endl;
        cout<<"2.Name"<<endl;
        cout<<"3.Age "<<endl;
        cout<<"4.Phone Number "<<endl;
        cout<<"5.Address "<<endl;
        cout<<"0.Thoat"<<endl;
        fflush(stdin);
        cin>>select;
        string y; int x;
        switch(select)
        {   
            case 0: break;
            case 1:
                cout<<"ID: ";
                fflush(stdin);
                getline(cin,y);
                (this->s+k)->setID(y);
                break;
            case 2:
                cout<<"Name: ";
                fflush(stdin);
                getline(cin,y);
                (this->s+k)->setname(y);
                break;
            case 3:
                cout<<"Age: ";
                fflush(stdin);
                cin>>x;
                (this->s+k)->setage(x);
                break;
            case 4:
                cout<<"Phone Number:";
                fflush(stdin);
                getline(cin,y);
                (this->s+k)->setphonenumber(y);
                break;
            case 5:
                cout<<"Address:";
                fflush(stdin);
                getline(cin,y);
                (this->s+k)->setaddress(y);
                break;
        }
        ofstream addfile("User.txt", ios::out| ios::trunc);
        for(int i=0;i<this->numUser;i++)
        {
            addfile<<(this->s+i)->getID()<<",";
            addfile<<(this->s+i)->getname()<<",";
            addfile<<(this->s+i)->getage()<<",";
            addfile<<(this->s+i)->getphonenumber()<<",";
            addfile<<(this->s+i)->getaddress();
            if(i<this->numUser-1) addfile<<endl;
        }
        addfile.close();
        fflush(stdin);
        cout<<"Chon 1 de tiep tuc || Chon 0 de thoat !"<<endl;
        cin>>select;
    } while (select == 1);
}
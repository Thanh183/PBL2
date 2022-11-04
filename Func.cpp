#include<fstream>
#include<cstdlib>
#include "Func.h"

Func::Func(int numBook,int numUser)
{   
    this->b=0;
    this->s=0;
    this->numBook=0;
    this->numUser=0;
}
Func::~Func()
{
}
int Func::getnumBook()
{
    return this->numBook;
}
void Func::setnumBook(int numBook)
{
    this->numBook=numBook;
}
void Func::readBook()
{   
    ifstream readfile("book.txt");
    while(! readfile.eof())
    {
        Book tmp;
        string numCode;
        getline(readfile,numCode,',');
        tmp.setnumCode(numCode);
        string name;
        getline(readfile,name,',');
        tmp.setname(name);
        string quantity;
        getline(readfile,quantity,',');
        tmp.setquantity(atoi(quantity.c_str()));
        string category;
        getline(readfile,category,',');
        tmp.setcategory(category);
        string author;
        getline(readfile,author,',');
        tmp.setauthor(author);
        string publisher;
        getline(readfile,publisher,',');
        tmp.setpublisher(publisher);
        string status;
        getline(readfile,status);
        tmp.setstatus(atoi(status.c_str()));
        if(this->numBook == 0)
        {   
            this->b=new Book[this->numBook+1];
            *(this->b +this->numBook)=tmp;
        }
        else
        {
            Book* q=new Book[this->numBook];
            for(int i=0;i<this->numBook;i++)
            {
                *(q+i)=*(this->b+i);
            }
            delete[] this->b;
            this->b=new Book[this->numBook+1];
            for(int i=0;i<this->numBook;i++)
            {
                *(this->b+i)=*(q+i);
            }
            *(this->b +this->numBook)=tmp;
            delete[] q;
        }
    ++this->numBook;
    }
    readfile.close();
    cout<<"Doc du lieu thanh cong!"<<endl;
}
void Func::showAll()
{
    for(int i=0;i<this->numBook;i++)
    {
        cout<<(this->b+i)->getnumCode()<<", ";
        cout<<(this->b+i)->getname()<<", ";
        cout<<(this->b+i)->getquantity()<<", ";
        cout<<(this->b+i)->getcategory()<<", ";
        cout<<(this->b+i)->getauthor()<<", ";
        cout<<(this->b+i)->getpublisher()<<", ";
        cout<<(this->b+i)->getstatus()<<endl;
    }
}
void Func::addBook()
{      
    showAll();
    ofstream addfile("book.txt", ios::out| ios::app);
    Book tmp;
    string s;
    int num;
    addfile<<endl;
    cout<<"Nhap ma sach: ";
    getline(cin,s);
    tmp.setnumCode(s);
    addfile<<tmp.getnumCode();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap ten sach: ";
    getline(cin,s);
    tmp.setname(s);
    addfile<<tmp.getname();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap so luong: ";
    cin>>num;
    tmp.setquantity(num);
    addfile<<tmp.getquantity();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap the loai: ";
    getline(cin,s);
    tmp.setcategory(s);
    addfile<<tmp.getcategory();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap ten tac gia: ";
    getline(cin,s);
    tmp.setauthor(s);
    addfile<<tmp.getauthor();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap ten NXB: ";
    getline(cin,s);
    tmp.setpublisher(s);
    addfile<<tmp.getpublisher();
    addfile<<",";
    fflush(stdin);
    cout<<"Nhap tinh trang: ";
    cin>>num;
    tmp.setstatus(num);
    addfile<<tmp.getstatus();
    if(this->numBook == 0)
    {   
        this->b=new Book[this->numBook+1];
        *(this->b +this->numBook)=tmp;
    }
    else
    {
        Book* q=new Book[this->numBook];
        for(int i=0;i<this->numBook;i++)
        {
            *(q+i)=*(this->b+i);
        }
        delete[] this->b;
        this->b=new Book[this->numBook+1];
        for(int i=0;i<this->numBook;i++)
        {
            *(this->b+i)=*(q+i);
        }
        *(this->b +this->numBook)=tmp;
        delete[] q;
    }
    ++this->numBook;
    addfile.close();
}
void Func::insertBook(int index)
{   
    showAll();
    ofstream addfile("book.txt", ios::out| ios::trunc);
    Book tmp;
    string name;
    string numCode;
    string category;
    int quantity;
    string author;
    string publisher;
    int status;
    cout<<"Nhap ma sach: ";
    getline(cin,numCode);
    tmp.setnumCode(numCode);
    fflush(stdin);
    cout<<"Nhap ten sach: ";
    getline(cin,name);
    tmp.setname(name);
    fflush(stdin);
    cout<<"Nhap so luong: ";
    cin>>quantity;
    tmp.setquantity(quantity);
    fflush(stdin);
    cout<<"Nhap the loai: ";
    getline(cin,category);
    tmp.setcategory(category);
    fflush(stdin);
    cout<<"Nhap ten tac gia: ";
    getline(cin,author);
    tmp.setauthor(author);
    fflush(stdin);
    cout<<"Nhap ten NXB: ";
    getline(cin,publisher);
    tmp.setpublisher(publisher);
    fflush(stdin);
    cout<<"Nhap tinh trang: ";
    cin>>status;
    tmp.setstatus(status);
    Book *q=new Book[this->numBook];
    for(int i=0;i<this->numBook;i++)
    {
        *(q+i)=*(this->b+i);
    }
    delete[] this->b;
    this->b=new Book[this->numBook+1];
    for(int i=0;i<this->numBook;i++)
    {   
        *(this->b+i)=*(q+i);
    }
    for(int i=index+1;i<=this->numBook;i++)
    {
        *(this->b+i)=*(this->b+i-1);
    }
    *(this->b+index)=tmp;
    delete[] q;
    ++this->numBook;
    for(int i=0;i<this->numBook;i++)
    {
        addfile<<(this->b+i)->getnumCode()<<",";
        addfile<<(this->b+i)->getname()<<",";
        addfile<<(this->b+i)->getquantity()<<",";
        addfile<<(this->b+i)->getcategory()<<",";
        addfile<<(this->b+i)->getauthor()<<",";
        addfile<<(this->b+i)->getpublisher()<<",";
        addfile<<(this->b+i)->getstatus();
        if(i<this->numBook-1) addfile<<endl;
    }
    addfile.close();
}

void Func::removeBook()
{   
    showAll();
    string temp;
    cout<<"Nhap ma sach muon xoa: ";
    getline(cin,temp);
    int k;
    for(int i=0;i<this->numBook;i++)
    {
        if((this->b+i)->getnumCode() == temp) 
            {   
                k=i;
                break;
            }
        if(i==this->numBook-1) cout<<"Khong ton tai!";
    }
    if(this->numBook >= 0)
    {
        if(this->numBook == 1) 
        {
            delete[] this->b;
            this->numBook=0;
        }
        else
        {
            Book *p=new Book[this->numBook];
            for(int i=0;i<this->numBook;i++)
            {
                *(p+i)=*(this->b +i);
            }
            delete[] this->b;
            this->b=new Book[this->numBook-1];
            for(int i=0;i<this->numBook-1;i++)
            {
                if(i<k)
                    *(this->b+i)=*(p+i);
                else *(this->b+i)=*(p+i+1);
            }   
            delete[] p;
        }
        this->numBook--;
    }
    ofstream addfile("book.txt", ios::out| ios::trunc);
    for(int i=0;i<this->numBook;i++)
    {
        addfile<<(this->b+i)->getnumCode()<<",";
        addfile<<(this->b+i)->getname()<<",";
        addfile<<(this->b+i)->getquantity()<<",";
        addfile<<(this->b+i)->getcategory()<<",";
        addfile<<(this->b+i)->getauthor()<<",";
        addfile<<(this->b+i)->getpublisher()<<",";
        addfile<<(this->b+i)->getstatus();
        if(i<this->numBook-1) addfile<<endl;
    }
    addfile.close();
}

void Func::updateBook()
{
    showAll();
    int select=0;
    do
    {   
        int k=0;
        string temp;
        cout<<"Chon sach can sua theo ma so :";
        fflush(stdin);
        getline(cin,temp);
        for(int i=0;i<this->numBook;i++)
        {
            if((this->b+i)->getnumCode() == temp)
            {
                k=i;
                break;
            }
            if(i==this->numBook-1) cout<<"Khong ton tai!";
        }
        cout<<"Chon so tu 1 den 7 sua:"<<endl;
        cout<<"1.Ma sach"<<endl;
        cout<<"2.Ten sach"<<endl;
        cout<<"3.So luong "<<endl;
        cout<<"4.The loai "<<endl;
        cout<<"5.Tac gia "<<endl;
        cout<<"6.NXB"<<endl;
        cout<<"7.Tinh trang"<<endl;
        cout<<"0.Thoat"<<endl;
        fflush(stdin);
        cin>>select;
        string s; int x;
        switch(select)
        {   
            case 0: break;
            case 1:
                cout<<"Nhap ma sach moi: ";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setnumCode(s);
                break;
            case 2:
                cout<<"Nhap ten sach moi: ";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setname(s);
                break;
            case 3:
                cout<<"Nhap so luong moi: ";
                fflush(stdin);
                cin>>x;
                (this->b+k)->setquantity(x);
                break;
            case 4:
                cout<<"Nhap the loai moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setcategory(s);
                break;
            case 5:
                cout<<"Nhap tac gia moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setauthor(s);
                break;
            case 6:
                cout<<"Nhap NXB moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setpublisher(s);
                break;
            case 7:
                cout<<"Nhap tinh trang moi:";
                fflush(stdin);
                cin>>x;
                (this->b+k)->setstatus(x);
                break;
        }
        ofstream addfile("book.txt", ios::out| ios::trunc);
        for(int i=0;i<this->numBook;i++)
        {
            addfile<<(this->b+i)->getnumCode()<<",";
            addfile<<(this->b+i)->getname()<<",";
            addfile<<(this->b+i)->getquantity()<<",";
            addfile<<(this->b+i)->getcategory()<<",";
            addfile<<(this->b+i)->getauthor()<<",";
            addfile<<(this->b+i)->getpublisher()<<",";
            addfile<<(this->b+i)->getstatus();
            if(i<this->numBook-1) addfile<<endl;
        }
        addfile.close();
        fflush(stdin);
        cout<<"Chon 1 de tiep tuc || Chon 0 de thoat !"<<endl;
        cin>>select;
    } while (select == 1);
}
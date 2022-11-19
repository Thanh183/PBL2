#include<fstream>
#include<cstdlib>
#include "Func.h"

Func::Func(int numBook)
{   
    this->b=0;
    this->numBook=0;
}
Func::~Func()
{
    delete[] this->b;
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
        string title;
        getline(readfile,title,',');
        tmp.settitle(title);
        string category;
        getline(readfile,category,',');
        tmp.setcategory(category);
        string author;
        getline(readfile,author,',');
        tmp.setauthor(author);
        string publisher;
        getline(readfile,publisher);
        tmp.setpublisher(publisher);
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
        cout<<(this->b+i)->gettitle()<<", ";
        cout<<(this->b+i)->getcategory()<<", ";
        cout<<(this->b+i)->getauthor()<<", ";
        cout<<(this->b+i)->getpublisher()<<endl;
    }
}
void Func::addBook()
{   
    readBook(); 
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
    tmp.settitle(s);
    addfile<<tmp.gettitle();
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
    // addfile<<",";
    fflush(stdin);
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
    readBook();
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
    tmp.settitle(name);
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
        addfile<<(this->b+i)->gettitle()<<",";
        addfile<<(this->b+i)->getcategory()<<",";
        addfile<<(this->b+i)->getauthor()<<",";
        addfile<<(this->b+i)->getpublisher();
        if(i<this->numBook-1) addfile<<endl;
    }
    addfile.close();
}

void Func::removeBook()
{   
    readBook();
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
        addfile<<(this->b+i)->gettitle()<<",";
        addfile<<(this->b+i)->getcategory()<<",";
        addfile<<(this->b+i)->getauthor()<<",";
        addfile<<(this->b+i)->getpublisher();
        if(i<this->numBook-1) addfile<<endl;
    }
    addfile.close();
}

void Func::updateBook()
{
    readBook();
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
        cout<<"3.The loai "<<endl;
        cout<<"4.Tac gia "<<endl;
        cout<<"5.NXB"<<endl;
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
                (this->b+k)->settitle(s);
                break;
            case 3:
                cout<<"Nhap the loai moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setcategory(s);
                break;
            case 4:
                cout<<"Nhap tac gia moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setauthor(s);
                break;
            case 5:
                cout<<"Nhap NXB moi:";
                fflush(stdin);
                getline(cin,s);
                (this->b+k)->setpublisher(s);
                break;
        }
        ofstream addfile("book.txt", ios::out| ios::trunc);
        for(int i=0;i<this->numBook;i++)
        {
            addfile<<(this->b+i)->getnumCode()<<",";
            addfile<<(this->b+i)->gettitle()<<",";
            addfile<<(this->b+i)->getcategory()<<",";
            addfile<<(this->b+i)->getauthor()<<",";
            addfile<<(this->b+i)->getpublisher();
            if(i<this->numBook-1) addfile<<endl;
        }
        addfile.close();
        fflush(stdin);
        cout<<"Chon 1 de tiep tuc || Chon 0 de thoat !"<<endl;
        cin>>select;
    } while (select == 1);
}
#include "Date.h"
Date::Date(int d, int m, int y):day(d),month(m),year(y)
{
}

Date::~Date()
{
}
void Date::showD()
{
    cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
}
#include<iostream>
#include"header.h"
#include<cstring>
using namespace std;

STRING::STRING()
{
        //default constructor
        p=0;
}


STRING::STRING(const char *ptr)
{
        //parmetrized constructor
        p=new char[strlen(ptr)+1];
        strcpy(p,ptr);
}


STRING::STRING(const STRING &temp)
{
        //copy constructor
        p=new char[strlen(temp.p)+1];
        strcpy(p,temp.p);
}

STRING::~STRING()
{
        //destructor
        delete []p;
}


int STRING::length()
{
        //string length
        int len=0;
        while(*p)
        {
                len++;
                p++;
        }
        return len;
}


const char* STRING::get()
{
        //get data
        return p;
}


void STRING::set(const char *s)
{
        //set data
        delete [] p;
        p=new char[strlen(s)+1];
        strcpy(p,s);
}


istream& operator>>(istream &in,STRING &s)
{
        // >> (insertion overloaded) set_data
        char buf[100];
        in.getline(buf,100);
        s.set(buf);
        return in;
}


ostream& operator<<(ostream &os,STRING &s)
{
        //<< (extraction overloaded) get_data
        os<<s.get();
        return os;
}



STRING STRING::operator=(STRING temp)
{
        // = overloaded
        p=new char[strlen(temp.p)+1];
        strcpy(p,temp.p);

        return *this;
}


char& STRING::operator[](int i)
{
        // [] overloaded
        return p[i];
}


STRING STRING::operator+(STRING temp)
{
        // + overloaded

        STRING ret;
        ret.p=new char[strlen(p)+strlen(temp.p)+1];
        strcat(ret.p,p);
        strcat(ret.p,temp.p);
        return ret;
}

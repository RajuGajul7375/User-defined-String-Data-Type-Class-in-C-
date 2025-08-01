#include<iostream>
using namespace std;

class STRING
{
        char *p;
        public:

        STRING();
        STRING(const char *);
        STRING(const STRING &temp);
        ~STRING();
        const char* get();
        void set(const char *s);

        // member function
        STRING operator=(STRING temp);
        char& operator [](int i);
        STRING operator+(STRING temp);
        int length();
        void modify();

        //friend member function
        friend istream& operator>>(istream &in,STRING &s);
        friend ostream& operator<<(ostream &os,STRING &s);
	friend int my_strlen(const STRING &temp);
	friend void my_strcpy(STRING &dest,const STRING &src);
	friend void my_strncpy(STRING &dest,const STRING &src,int n);
	friend void my_strcat(STRING &dest,const STRING &src);
	friend void my_strncat(STRING &dest,const STRING &src,int n);
	friend int my_strcmp(const STRING &s1,const STRING &s2);
	friend int my_strncmp(const STRING &s1,const STRING &s2,int n);
	friend char* my_strchr(const STRING &s,char ch);
	friend char* my_strrchr(const STRING &s,char ch);
	friend char* my_strstr(const STRING &s,const STRING &sub);
	friend void my_strupper(STRING &s);
	friend void my_strlower(STRING &s);
	friend void my_strtoggle(STRING &s);
	friend void my_strrev(STRING &s);

};

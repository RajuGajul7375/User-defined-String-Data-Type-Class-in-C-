#include<iostream>
using namespace std;
#include"header.h"

int my_strlen(const STRING &temp)
{
	int len=0;
	while(temp.p[len])
		len++;
	return len;

}



void my_strcpy(STRING &dest,const STRING &src)
{
	delete []dest.p;
	dest.p=new char[my_strlen(src)+1];
	int i=0;
	while(src.p[i])
	{
		dest.p[i]=src.p[i];
		i++;
	}
	dest.p[i]='\0';
}


void my_strncpy(STRING &dest,const STRING &src,int n)
{
	delete []dest.p;
        dest.p=new char[n+1];
        int i=0;
        while(i<n)
        {
                dest.p[i]=src.p[i];
                i++;
        }
        dest.p[i]='\0';
}


int my_strcmp(const STRING &s1,const STRING &s2)
{
	int i;
	for(i=0;s1.p[i]&&s2.p[i];i++)
	{
		if(s1.p[i]!=s2.p[i])
			break;
	}

	if(s1.p[i]!=s2.p[i])
		return s1.p[i]-s2.p[i];
	else
		return 0;

}

int my_strncmp(const STRING &s1,const STRING &s2,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s1.p[i]!=s2.p[i])
		{
			return s1.p[i]-s2.p[i];
			break;
		}
	}
                return 0;
}

char* my_strchr(const STRING &s,char ch)
{
	int i;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]==ch)
			return &(s.p[i]);
	}
	return nullptr;
}

char* my_strrchr(const STRING &s,char ch)
{
	int i;
	i=my_strlen(s.p);
	for(i--;i>=0;i--)
	{
		if(s.p[i]==ch)
			return &(s.p[i]);
	}
	return nullptr;
}


char* my_strstr(const STRING &s,const STRING &sub)
{
	int i,j;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]==sub.p[0])
		{
			for(j=1;sub.p[j];j++)
			{
				if(s.p[j+i]!=sub.p[j])
					break;
			}
			if(sub.p[j]=='\0')
				return &(s.p[i]);

		}
	}
	return nullptr;
}

void my_strupper(STRING &s)
{
	int i;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]>='a'&&s.p[i]<='z')
			s.p[i]=s.p[i]-32;
	}
}


void my_strlower(STRING &s)
{
	int i;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]>='A'&&s.p[i]<='Z')
			s.p[i]=s.p[i]+32;
	}
}

void my_strtoggle(STRING &s)
{
	int i;
	for(i=0;s.p[i];i++)
	{
		if((s.p[i]>='a'&&s.p[i]<='z')||(s.p[i]>='A'&&s.p[i]<='Z'))
			s.p[i]=s.p[i]^32;
	}
}


void my_strrev(STRING &s)
{
	int len,i,j;
	char t;
	len=my_strlen(s.p);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		t=s.p[i];
		s.p[i]=s.p[j];
		s.p[j]=t;
	}
}

void my_strcat(STRING &dest,const STRING &src)
{
	int len,i,j;
	len=my_strlen(dest);

	STRING temp;
	temp.p=new char[len+1];
	my_strcpy(temp,dest);

	delete []dest.p;
	dest.p=new char[my_strlen(src)+len+1];
	
	my_strcpy(dest,temp);
	for(i=0,j=len;src.p[i];i++,j++)
		dest.p[j]=src.p[i];

	dest.p[j]='\0';

}



void my_strncat(STRING &dest,const STRING &src,int n)
{
	int len,i,j;
	len=my_strlen(dest);

	STRING temp;
	temp.p=new char[len+1];
	my_strcpy(temp,dest);

	delete []dest.p;
	dest.p=new char[len+1+n];

	my_strcpy(dest,temp);
	for(i=0,j=len;i<n;i++,j++)
		dest.p[j]=src.p[i];

	dest.p[j]='\0';

}







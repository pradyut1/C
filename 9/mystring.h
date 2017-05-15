#ifndef __MYSTRING_H
#define __MYSTRING_H

#include <iostream>

using namespace std;

class String
{
private:
	char *strval;               //string value
	int strln;                  //length of string value

public:
	//constructors & destructors
	String(): strval(NULL), strln(0)
	{}
    String(const String &s);
	String(char s[]);           //initialize string value to s
    ~String()
    {delete[] strval;}

	//accessor functions/operators
	int Length() const
	{return strln;}
	int SubString(String s, int startpos=0) const;
	String SubString(int startpos, int endpos) const;
	void ToCstring(char cs[]);  //pass back string value in cs as Cstring

	bool operator ==(String s) const;
	bool operator >(String s) const;
	bool operator <(String s) const;
	String operator +(String s) const;

	//modifier/mutator functions/operators
    void ToLower();
    void ToUpper();
    void Append(String s);
    String operator=(String s);
    String operator+=(String s);
	bool Replace(int startpos, int endpos, String s);
	bool Replace(String targetstr, String replacestr);
	bool Insert(String s, int pos=0);

	char& operator [](int indx)
    {return strval[indx];}

	//input/output functions
	friend istream& operator >>(istream &strm, String &strng);
	friend ostream& operator <<(ostream &strm, String strng);
};

#endif
#ifndef __MYSTRING_H
#define __MYSTRING_H

#include <iostream>

using namespace std;

const int MAXSIZE=100;

class String
{
private:
	char strval[MAXSIZE];       //string value
	int strln;                  //length of string value

public:
	//constructors
	String(): strln(0)
	{}
	String(char s[]);           //initialize string value to s

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
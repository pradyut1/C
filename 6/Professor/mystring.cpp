#include <iostream>
#include "mystring.h"

using namespace std;

//constructors

String::String(char s[])
{
	for (strln=0; (strln<MAXSIZE) && s[strln]; strln++)
		strval[strln] = s[strln];
}

//accessor functions/operators

bool String::operator ==(String s) const
{
	int indx=0;

	if (strln == s.strln)
		for ( ; (indx<strln) && (strval[indx]==s.strval[indx]); indx++)
			;
	return (strln==s.strln) && (indx==strln);
}

bool String::operator >(String s) const
{
	int i=0,
        shorterLngth = (strln<s.strln) ? strln : s.strln;

    for (; (i < shorterLngth) && (strval[i] == s.strval[i]); i++)
        ;

    return (((i<shorterLngth) && (strval[i] > s.strval[i]))
                || ((i==shorterLngth) && (strln > s.strln)));
}

bool String::operator <(String s) const
{
    int i = 0,
        shorterLngth = (strln<s.strln) ? strln : s.strln;

    for (; (i < shorterLngth) && (strval[i] == s.strval[i]); i++)
        ;

    return (((i<shorterLngth) && (strval[i] < s.strval[i]))
                || ((i==shorterLngth) && (strln < s.strln)));
}

String String::operator +(String s) const
{
    String result;

    for (result.strln = 0; result.strln < strln; result.strln++)
        result.strval[result.strln] = strval[result.strln];

    for (int i=0; (i<s.strln) && (result.strln < MAXSIZE); i++, result.strln++)
        result.strval[result.strln] = s.strval[i];

    return result;
}

void String::ToCstring(char cs[])    //pass back string value in cs as Cstring
{
    for (int i = 0; i < strln; i++)
        cs[i] = strval[i];
    cs[strln] = '\0';                  //append null character
}

//modifier/mutator functions/operators

void String::ToLower()
{
    for (int i = 0; i < strln; i++)
        if ((strval[i] >= 'A') && (strval[i] <= 'Z'))
            strval[i] |= 0x20;
}

void String::ToUpper()
{
    for (int i = 0; i < strln; i++)
        if ((strval[i] >= 'a') && (strval[i] <= 'z'))
            strval[i] &= 0xdf;
}

void String::Append(String s)
{
    for (int i = 0; (i < s.strln) && (strln < MAXSIZE); i++, strln++)
        strval[strln] = s.strval[i];
}

String String::operator+=(String s)
{
    char result[101];

    for (int i = 0; i < strln; i++)
        result[i] = strval[i];

    for (int i = 0; (i<s.strln) && (strln < MAXSIZE); i++, strln++)
        result[strln] = strval[strln] = s.strval[i];

    result[strln] = '\0';

    return result;
}

int String::SubString(String s, int startpos) const
{
    int foundPos = -1,       //indicates s not as yet found as a substring
        i,
        j;
    while ((startpos + s.strln <= strln) && (foundPos == -1)) {
        for (i = startpos, j = 0; strval[i] == s.strval[j]; i++, j++)
            ;
        if (j == s.strln)
            foundPos = startpos;
        else
            startpos++;
    }

    return foundPos;
}

String String::SubString(int startpos, int endpos) const
{
    String result;                //initial value is null string

    if ((startpos >= 0) && (endpos < strln))
        for (; startpos <= endpos; startpos++)
            result.strval[result.strln++] = strval[startpos];
    //else do nothing, since startpos or endpos value is invalid

    return result;
}


istream& operator >>(istream &strm, String &strng)
{
    char inputString[101];

    strm >> inputString;
    strng = inputString;

    return strm;
}

ostream& operator <<(ostream &strm, String strng)
{
    for (int i = 0; i < strng.strln; i++)
        strm << strng.strval[i];

    return strm;
}

bool String::Replace(int startpos, int endpos, String s)
{
	bool result=false;          //substring not yet replaced
	char tempStrVal[100];
    int tempStrLngth=0;

	if ((startpos>=0) && (endpos<strln)) {
        for (int i=endpos+1; i < strln; i++)
            tempStrVal[tempStrLngth++] = strval[i];
        strln = startpos;
        for (int i = 0; (i < s.strln) && (strln < MAXSIZE); i++)
            strval[strln++] = s.strval[i];
        for (int i = 0; (i < tempStrLngth) && (strln < MAXSIZE); i++)
            strval[strln++] = tempStrVal[i];
        result = true;
	}

    return result;
}

bool String::Replace(String targetstr, String replacestr)
{
    bool result = false;
    int targetstrPos = SubString(targetstr);

    if (targetstrPos != -1) {
        Replace(targetstrPos, (targetstrPos + targetstr.strln - 1), replacestr);
        result = true;
    }

    return result;
}

bool String::Insert(String s, int pos)
{
    bool result = false;
    char tempStrVal[100];
    int tempStrLngth = 0;

    if ((pos >= 0) && (pos < strln)) {
        for (int i = pos; i < strln; i++)
            tempStrVal[tempStrLngth++] = strval[i];
        strln = pos;
        for (int i = 0; (i < s.strln) && (strln < MAXSIZE); i++)
            strval[strln++] = s.strval[i];
        for (int i = 0; (i < tempStrLngth) && (strln < MAXSIZE); i++)
            strval[strln++] = tempStrVal[i];
        result = true;
    }

    return result;
}

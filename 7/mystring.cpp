#include <iostream>
#include "mystring.h"

using namespace std;

//constructors

String::String(const String &s)
{
    strval = new (char[s.strln]);

    for (strln=0; strln < s.strln; strln++)
        strval[strln] = s.strval[strln];
}

String::String(char s[])
{
	strln = strlen(s);
    strval = new (char[strln]);
    
    for (int i=0; s[i]; i++)
		strval[i] = s[i];
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

    result.strval = new (char[strln + s.strln]);

    for (result.strln = 0; result.strln < strln; result.strln++)
        result.strval[result.strln] = strval[result.strln];

    for (int i=0; (i < s.strln); i++, result.strln++)
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
    if (s.strln) {           //if not equal to 0
        char *tempStr = new (char[strln + s.strln]);

        for (int i=0; i < strln; i++)
            tempStr[i] = strval[i];

        for (int i = 0; i < s.strln; i++, strln++)
            tempStr[strln] = s.strval[i];

        delete[] strval;
        strval = tempStr;
    }
}

String String::operator+=(String s)
{
    *this = *this + s;
    
    return *this;
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

    if ((startpos >= 0) && (endpos < strln) && (startpos <= endpos)) {
        result.strval = new (char[endpos - startpos + 1]);

        for (; startpos <= endpos; startpos++)
            result.strval[result.strln++] = strval[startpos];
    }
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
	char *tempStrVal;
    int tempStrLngth=0;
    
	if ((startpos>=0) && (endpos<strln) && (startpos <= endpos)) {
        tempStrVal = new (char[strln - (endpos - startpos + 1) + s.strln]);

        for ( ; tempStrLngth < startpos; tempStrLngth++)
            tempStrVal[tempStrLngth] = strval[tempStrLngth];

        for (int i=0; i < s.strln; i++, tempStrLngth++)
            tempStrVal[tempStrLngth] = s.strval[i];

        for (int i=endpos+1; i < strln; i++, tempStrLngth++)
            tempStrVal[tempStrLngth] = strval[i];

        delete[] strval;
        strval = tempStrVal;
        strln = tempStrLngth;

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
    char *tempStrVal;
    int tempStrLngth = 0;

    if ((pos >= 0) && (pos < strln)) {
        if (s.strln) {            //s is not a null string
            tempStrVal = new (char[strln + s.strln]);

            for ( ; tempStrLngth < pos; tempStrLngth++)
                tempStrVal[tempStrLngth] = strval[tempStrLngth];

            for (int i=0; i < s.strln; i++, tempStrLngth++)
                tempStrVal[tempStrLngth] = s.strval[i];

            for (int i=pos; i < strln; i++, tempStrLngth++)
                tempStrVal[tempStrLngth] = strval[i];

            delete[] strval;
            strval = tempStrVal;
            strln = tempStrLngth;
        }

        result = true;
    }

    return result;
}

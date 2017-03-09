#include "mystring.h"
using namespace std;

String::String(char s[])    //initialize string value to s
{
    for (strln = 0; s[strln]; strln++)
        strval[strln] = s[strln];
}

int String::SubString(String s, int startpos) const
{
    if (s.strln > strln)
        return -1;

    for (int i = 0; i < strln; i++) {
        int j = 0;
        if (strval[i] == s.strval[j]) {
            while (strval[i] == s.strval[j] && j < s.strln) {
                j++;
                i++;
            }

            if (j == s.strln)
                return i-s.strln;
        }
    }
    return -1;
}


String String::SubString(int startpos, int endpos) const
{
    String temp;
    for (temp.strln = 0; temp.strln <= (endpos - startpos); temp.strln++)
        temp.strval[temp.strln] = strval[startpos + temp.strln];
    temp.strln = endpos - startpos+1;
    return temp;
}

void String::ToCstring(char cs[])   //pass back string value in cs as Cstring
{
    int i = 0;
    for (i = 0; i < strln; i++)
        cs[i] = strval[i];
    cs[i] = '\0';
}

bool String::operator ==(String s) const
{
    int j=0;
    for (int i = 0; i < strln; i++)
        if (s.strval[i] == strval[i])
            j++;
    if (j == s.strln)
        return true;
    return false;
}

bool String::operator >(String s) const
{
    int i= -1;

    do(i++);
    while (strval[i] == s.strval[i] | strval[i] == s.strval[i] + 32 | strval[i] == s.strval[i] - 32); //checking if the chars are equal irrespective of the case

    if (strln >= s.strln)
    {
        if (i<s.strln && strval[i] > s.strval[i])
            return true;
        else {
            if (i > s.strln && strval[s.strln] > s.strval[s.strln])
                return true;
        }
    }

    else
    {
        if (strln < s.strln)
        {
            if (i<strln && strval[i] > s.strval[i])
                return true;
            else {
                if (i > strln && strval[strln] > s.strval[strln])
                    return true;
            }
        }
    }
    return false;
}

bool String::operator <(String s) const
{
    int i = -1;

    do(i++);
    while (strval[i] == s.strval[i] | strval[i] == s.strval[i] + 32 | strval[i] == s.strval[i] - 32); //checking if the chars are equal irrespective of the case

    if (strln >= s.strln)
    {
        if (i<s.strln && strval[i] < s.strval[i])
            return true;
        else {
            if (i > s.strln && strval[s.strln] < s.strval[s.strln])
                return true;
        }
    }

    else
    {
        if (strln < s.strln)
        {
            if (i<strln && strval[i] < s.strval[i])
                return true;
            else {
                if (i > strln && strval[strln] < s.strval[strln])
                    return true;
            }
        }
    }
    return false;
}

String String::operator +(String s) const
{
    String temp;
    int i;
    for (i = 0; i < strln; i++)
        temp[i] = strval[i];
    for (i = strln; i < (strln + s.strln); i++)
        temp[i] = s[i - strln];
    temp.strln = strln + s.strln;
    return temp;
}

//modifier/mutator functions/operators
void String::ToLower()
{
    for (int i = 0; i<strln; i++)
        if ((strval[i] >= 'A') && (strval[i] <= 'Z'))      //if uppercase
            strval[i] |= 0x20;
}

void String::ToUpper()
{
    for (int i = 0; i<strln; i++)
        if (strval[i] > 'Z')                             //if lowercase
            strval[i] -=32;
}

void String::Append(String s) {
    for (int i = strln; i < (strln + s.strln); i++)
        strval[i] = s.strval[i - strln];
    strln = (strln + s.strln);
}

String String::operator +=(String s)
{
    String temp;
    for (int i = 0; i<strln; i++)
        temp[i] = strval[i];
    for (int i = 0; i < s.strln; i++)
        temp[i+strln] = s[i];
    temp.strln = strln + s.strln;
    for (int i = strln; i < (strln + s.strln); i++)
        strval[i]= s[i - strln];
    strln += s.strln;
    
    return temp;
}

bool String::Replace(int startpos, int endpos, String s)
{
    if (startpos >= strln | endpos >= strln)
        return false;
    else
    {
        String temp;
        int i;
        for (i = 0; i < strln - endpos; i++) // store the string starting from the next char to endpos in temp
            temp.strval[i] = strval[endpos + 1 + i];
        temp.strln = strln - endpos - 1;
        for (i = 0; i < s.strln; i++) // replacing the string from startpos with s
            strval[i + startpos] = s[i];
        for (i = 0; i < temp.strln; i++) // Appending temp and adjusting strln
            strval[startpos + s.strln + i] = temp[i];
        strln = strln - (endpos - startpos) + s.strln - 1;
        return true;
    }
}

bool String::Replace(String targetstr, String replacestr)
{
    String temp;
    int j = SubString(targetstr); // position from which the targetstr starts
    if (j == -1)
        return false;
    else
    {
        for (int i = 0; i < strln - j - targetstr.strln; i++)//adding the later part of strval to temp
            temp.strval[i] = strval[j + targetstr.strln + i];
        temp.strln = strln - j - targetstr.strln;

        for (int i = 0; i < replacestr.strln; i++)              //adding replacestr to strval
            strval[j + i] = replacestr.strval[i];

        for (int i = 0; i < temp.strln; i++) //appending temp and adjusting strln
            strval[j + replacestr.strln + i] = temp.strval[i];
        strln = strln - targetstr.strln + replacestr.strln;
        return true;
    }
}

bool String::Insert(String s, int pos)
{
    if (pos >= strln)
        return false;
    else
    {
        String temp;
        for (int i = 0; i < strln - pos + 1; i++) // adding the later part of strval from pos index to temp
            temp.strval[i] = strval[pos + i];
        temp.strln = strln - pos + 1;

        for (int i = 0; i < s.strln; i++) //inserting s
            strval[pos + i] = s.strval[i];

        for (int i = 0; i < temp.strln; i++) //appending temp and adjusting strln
            strval[pos + s.strln + i] = temp[i];
        strln = strln + s.strln;
        return true;
    }
}

//input/output functions

istream& operator >> (istream& strm, String& strng)
{
    char temp[101];
    strm >> temp;
    for (strng.strln = 0; temp[strng.strln]; strng.strln++)
        strng.strval[strng.strln] = temp[strng.strln];
    return strm;
}

ostream& operator<<(ostream& strm, String strng)
{
    int i = 0;
    for (i = 0; i < strng.strln; i++)
        strm << strng.strval[i];
    return strm;
}

#include "mystring.h"
using namespace std;


bool IsPalindrome(String strng)
{
    strng.ToLower();
    if (strng.Length() == 1)
        return true;
    int j = -1;
    String temp1, temp2;
    if ((strng.Length() % 2) == 0)
    {

        temp1 = strng.SubString(0, (strng.Length() / 2) - 1);
        temp2 = strng.SubString((strng.Length() / 2), strng.Length() - 1);

        do(j++);
        while (temp1[j] == temp2[(strng.Length() / 2) - 1 - j] && j < (strng.Length()) / 2);

        if (j == strng.Length() / 2)
            return true;
        else
            return false;
    }

    else
    {
        temp1 = strng.SubString(0, ((strng.Length() - 3) / 2));
        temp2 = strng.SubString((((strng.Length() + 1) / 2)), strng.Length() - 1);
            do(j++);
            while (temp1[j] == temp2[(strng.Length() - 3) / 2 - j] && j< (strng.Length() - 1) / 2);
        if (j == (strng.Length() - 1) / 2)
            return true;
        else
            return false;
    }
}

void ToLowers(char s[])
{
    for (int i = 0; s[i]; i++)
        if ((s[i] >= 'A') && (s[i] <= 'Z'))      //if uppercase
            s[i] |= 0x20;
}

bool MoreData()
{
    char yesNoResponse[4];

    do {
        cout << "Is there a word to be input? (yes/no): ";
        cin >> yesNoResponse;
        ToLowers(yesNoResponse);
    } while (strcmp(yesNoResponse, "yes") && strcmp(yesNoResponse, "no"));

    return (strcmp(yesNoResponse, "yes") == 0);
}

void Sort(String list[], int count)
{
    String temp1, temp2;
    for (int i = count - 1; i; i--)
        for (int j = 0; j < i; j++)
        {
            temp1 = list[j];
            temp2 = list[j + 1];
            temp1.ToLower();
            temp2.ToLower();
            if (temp1 > temp2)
                swap(list[j], list[j + 1]);
        }
}

void main()
{
    String StrngList[100];
    int arrCount = 0;
    while (MoreData()) {
        cout << "Enter the word: ";
        cin >> StrngList[arrCount++];        
    }

    Sort(StrngList, arrCount);

    for (int i = 0; i < arrCount; i++)
    {
        if (IsPalindrome(StrngList[i]))
            cout << StrngList[i] << '\t' << "Palindrome" << endl;
        else
            cout << StrngList[i] << endl;
    }

}
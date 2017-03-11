#include <iostream>
#include "mystring.h"

using namespace std;

void Sort(String wrdList[], int wrdCount);
void Swap(String &s1, String &s2);
bool IsPalindrome(String s);
bool MoreData();

const int MAX = 100;
void main()
{
    String inList[MAX];                 //list of input words
    int inWrdCount = 0,                //number of words input to program
        palindromeCount = 0;           //number of words that are palindromes

    //get data from user
    while (MoreData() && inWrdCount < MAX) {
        cout << "Please enter a word to be processed: ";
        cin >> inList[inWrdCount];
        inList[inWrdCount++].ToLower();
    }

    //sort and output results
    Sort(inList, inWrdCount);

    cout << "\nWord List\n";

    for (int i = 0; i < inWrdCount; i++) {
        cout << inList[i];
        if (IsPalindrome(inList[i])) {
            cout << " palindrome";
            palindromeCount++;
        }
        cout << endl;
    }

    cout << "\nNumber of words in list that are palindromes: "
        << palindromeCount << endl;
}


void Sort(String wrdList[], int wrdCount)
{
    for (int i = wrdCount - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (wrdList[j] > wrdList[j + 1])
                Swap(wrdList[j], wrdList[j + 1]);
}

void Swap(String &s1, String &s2)
{
    String temp;

    temp = s1;
    s1 = s2;
    s2 = temp;
}

bool IsPalindrome(String s)
{
    int startPos = 0,                  //start position of s
        endPos = s.Length() - 1;       //end position of s

    for (; (startPos < endPos) && (s[startPos] == s[endPos]); startPos++, endPos--)
        ;

    return (startPos >= endPos);
}

bool MoreData()
{
    String ynResponse;                //yes/no response from user

    do {
        cout << "Do you have a word to be input (yes/no)? ";
        cin >> ynResponse;
        ynResponse.ToLower();
    } while (!(ynResponse == "yes") && !(ynResponse == "no"));

    return (ynResponse == "yes");
}


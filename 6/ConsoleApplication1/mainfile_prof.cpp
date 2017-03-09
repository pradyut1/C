#include <iostream>
#include "mystring.h"

using namespace std;

void main1()
{
    String s1,
        s2("abcdefghi"),
        s3("jklmn"),
        s4;
    char cstring[101];

    s4 = s2 + s3;

    cout << "s1 length: " << s1.Length() << '\t' << s1 << endl;
    cout << "s2 length: " << s2.Length() << '\t' << s2 << endl;
    cout << "s3 length: " << s3.Length() << '\t' << s3 << endl;
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;

    cout << "s2.SubString(\"cdef\"): " << s2.SubString("cdef") << endl;
    cout << "s2.SubString(2, 5): \"" << s2.SubString(2, 5) << "\"" << endl;

    s2.ToCstring(cstring);
    cout << "Cstring value of s2: \"" << cstring << "\"" << endl;

    s1 = s2;
    if (s1 == s2) cout << '1';
    if (s4 > s1) cout << "\t2";
    if (s1 < s4) cout << "\t3";
    if (!(s1 == s3)) cout << "\t4";
    if (!(s1 > s4)) cout << "\t5";
    if (!(s4 < s1)) cout << "\t6";
    if (!(s1 == s4)) cout << "\t7\n" << endl;

    s4.Append("XYZ");
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;
    s4.Replace(2, 4, "XXXX");
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;
    s4.Replace("XXXX", "YY");
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;

    s4.Insert("ZZZ", 8);
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;

    s4.ToLower();
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;

    s4.ToUpper();
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;

    s4[9] = 'z';
    cout << "s4 length: " << s4.Length() << '\t' << s4 << endl;
    cout << "s4[9]: '" << s4[9] << "'" << endl;

    cout << "\nEnter the string value \"success\": ";
    cin >> s1;
    cout << "The value entered: \"" << s1 << "\"\nwhich was "
        << ((s1 == "success") ? "" : "not ")
        << "the requested value\n" << endl;

    s2 = "abc";
    s3 = "defg";
    s1 = s2 += s3;
    cout << s1 << '\t' << s2 << '\t' << s3 << endl;

    cout << "\nend of program\n" << endl;
}
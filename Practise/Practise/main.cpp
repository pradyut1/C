//Given a number (n) , the task is to find if its divisible by 11 or not. 

//Input:
//The first line of input contains an  integer T denoting the no of test 
//cases.Then T test cases follow.Each test case contains an numer x.

//Output:
//For each test case in a new line print 1 if n is divisible by 11 else print 0.
        //Constraints:
        //    1 <= T <= 100
         //       1 <= N <= 10 ^ 100 + 5#include <iostream>
#include <iostream>
using namespace std;

int main() {
    int T;
    int *n;

    cout << "Number of integers to be tested?: " << endl;
    cin >> T;

    n = new int[T];
    int i;
    for (i = 0; i < T; i++)
    {
        cout << "Enter Number: " << endl;
        cin >> n[i];
    }
    for (i = 0; i<T; i++)
    {
        if (n[i] % 11 == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

//function declarations
bool IsPrime(int num);       //returns true  if num is prime, else returns false
int Prime(int n);            //returns the nth prime number

//function definitions
void main()
{
    char menuOption;
    int inValue;             //input value from user

    do {
        //display menu and obtain option from user
        cout << "\n  - Menu Options - \n"
            << "\nF:\tFind the nth prime number"
            << "\nT:\tTest a value to see if it is prime"
            << "\nQ:\tTerminate Program"
            << "\n\n Option: ";

        cin >> menuOption;
        menuOption |= 0x20;       //convert to lowercase

        //process selected option
        switch (menuOption)
        {
        case 'f':
            cout << "This option outputs nth prime number; enter value of n: ";
            cin >> inValue;
            cout << "\nThe nth prime number, where n is " << inValue << " is "
                << Prime(inValue) << endl;
            break;

        case 't':
            cout << "Enter the value to be tested: ";
            cin >> inValue;
            cout << '\n' << inValue << " is "
                << ((IsPrime(inValue)) ? "prime" : "not prime")
                << endl;
            break;

        case 'q':
            cout << "\nProgram terminating\n" << endl;
            break;

        default:
            cout << "Invalid selection" << endl;
            break;
        }
             
    } while (menuOption != 'q');
}

bool IsPrime(int num)        //returns true  if num is prime, else returns false
{
    int divisor;             //used to determine if parameter num is prime
    bool result = true;

    for (divisor = 2; divisor <= (num / divisor); divisor++)
        if ((num % divisor) == 0) {      //num has divisor, therefore is not prime
            result = false;
            break;
        }

    return result && (num != 1);
}

int Prime(int n)             //returns the nth prime number
{
    int primeCount=0,        //number of primes found
        result = 0;          //nth prime number, to be returned

    if (n == 1)
        result = 2;
    else
        if (n > 1) {
            primeCount = 2;
            result = 3;
            while (primeCount < n) {        //continue testing values until nth
                result += 2;                //nth prime is found
                if (IsPrime(result))
                    primeCount++;
            }
        }
    return result;
}
#include <iostream>

using namespace std;

void main()
{
    int valCount=0,         //number of values entered
        negCount=0,         //number of negative values
        evenCount=0,        //number of even values
        oddCount=0,         //number of odd values
        inValAsInt;         //integer version of input value

    float inValue,           //user input value
          sum=0;             //sum of values entered

    char yes_no_response;

    cout << "\nDo you have a value to enter? (Y/N): ";
    cin >> yes_no_response;
    yes_no_response = yes_no_response | 0x20;     //convert to lower case

    //validate user response
    while ((yes_no_response != 'y') && (yes_no_response != 'n')) {
        cout << "Invalid response. Enter 'Y' or 'N': ";
        cin >> yes_no_response;
        yes_no_response = yes_no_response | 0x20;     //convert to lower case
    }

    //The following while construct reads and processes the user's data
    while (yes_no_response == 'y') {
        cout << "Enter value: ";
        cin >> inValue;
        sum += inValue;
        valCount++;


        if (inValue < 0)
            negCount++;

        inValAsInt = static_cast<int>(inValue); //convert input value to int

        if(inValAsInt == inValue)               //input value is an integer
            if((inValAsInt % 2) == 0)             //input value is even
                evenCount++;
			else
                oddCount++;

        cout << "Do you have another value to be processed? (Y/N): ";
        cin >> yes_no_response;
        yes_no_response |= 0x20;       //convert input response to lower case

        //validate user response
        while ((yes_no_response != 'y') && (yes_no_response != 'n')) {
            cout << "Invalid response. Enter 'Y' or 'N': ";
            cin >> yes_no_response;
            yes_no_response |= 0x20;       //convert response to lower case
        }
    }

    //Output program results
    cout << "\nThe statistics for your program are as follows:"
         << "\nNumber of values entered: " << valCount
         << "\nSum of values entered: " << sum
         << "\nNegative value count: " << negCount
         << "\nAverage of values entered: "
         << (valCount ? sum/valCount : 0.0)    //avoids division by zero
         << "\nEven value count: " << evenCount
         << "\nOdd value count: " << oddCount
		 << "\n\n" << endl;
}


//Program Output with Sample Data
/*

Do you have a value to enter? (Y/N): y
Enter value: 12.43
Do you have another value to be processed? (Y/N): Y
Enter value: -24.0
Do you have another value to be processed? (Y/N): y
Enter value: 105
Do you have another value to be processed? (Y/N): y
Enter value: 0
Do you have another value to be processed? (Y/N): y
Enter value: 3.141
Do you have another value to be processed? (Y/N): y
Enter value: -43.24
Do you have another value to be processed? (Y/N): y
Enter value: 2.0
Do you have another value to be processed? (Y/N): y
Enter value: -1
Do you have another value to be processed? (Y/N): n

The statistics for your program are as follows:
Number of values entered: 8
Sum of values entered: 54.331
Negative value count: 3
Average of values entered: 6.79137
Even value count: 3
Odd value count: 2


Press any key to continue . . .

*/
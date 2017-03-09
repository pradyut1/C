#include <iostream>

using namespace std;

void main()
{
    double radius,
        areaInches;
    const double PI = 3.1415926,
        SQInches2SQCENTS = 6.4516;

    cout << "\nyour name\n\n";
    cout << "Enter circle radius value in incches to have area computed: ";
    cin >> radius;

    areaInches = PI * radius * radius;

    cout << "\nThe area of the circle of radius " << radius << " inches is "
        << '\n' << areaInches << " square inches and "
        << (areaInches * SQInches2SQCENTS) << " square centimeters\n" << endl;
}
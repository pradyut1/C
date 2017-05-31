#include <iostream>

using namespace std;

int min(int p1, int p2)
{
    return (p1 < p2) ? p1 : p2;
}

int max(int p1, int p2)
{
    return (p1 < p2) ? p2 : p1;
}

int sum(int p1, int p2)
{
    return p1 + p2;
}

void f1(int(*fparam) (int, int))
{
    cout << "fparam/sum: " << fparam(7, 14) << endl;
}

void main()
{
    int v1 = 7,
        v2 = 14;

    int(*fcn) (int, int);

    fcn = min;
    cout << "fcn/min: " << fcn(v1, v2) << endl;

    fcn = max;
    cout << "fcn/max: " << fcn(v1, v2) << endl;

    f1(sum);


}
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double r;
    cin >> r;
    r = abs(r);

    cout << fixed;
    cout.precision(6);
    cout << pow(r, 2) * M_PI << endl;
    cout << pow(r, 2) + pow(r, 2);
}
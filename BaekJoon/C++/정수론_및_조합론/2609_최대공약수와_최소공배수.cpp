#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int LCM(int a, int b, int gcd)
{
    return (a * b) / gcd;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int gcd = GCD(n1, n2);
    int lcm = LCM(n1, n2, gcd);

    cout << gcd << endl;
    cout << lcm << endl;
}
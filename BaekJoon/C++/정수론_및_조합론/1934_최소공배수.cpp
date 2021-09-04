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
    int T;
    cin >> T;
    int n1, n2;

    for (int i = 0; i < T; i++)
    {
        cin >> n1 >> n2;
        int gcd = GCD(n1, n2);
        int lcm = LCM(n1, n2, gcd);
        cout << lcm << endl;
    }
}
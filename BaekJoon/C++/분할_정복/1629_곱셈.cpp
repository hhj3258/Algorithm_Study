#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long Solve(const long long a, const long long b)
{
    if (b == 0)
        return 1;

    // a^b = a^(b/2) * a^(b/2)   -> b가 짝수
    // a^11 = a^(5) * a^(5) * a  -> b가 홀수

    long long temp = Solve(a, b / 2);
    temp = (temp * temp) % C;

    if (b % 2 == 1)
        return a * temp % C;
    else
        return temp;
}

int main()
{
    cin >> A >> B >> C;

    cout << Solve(A, B);
}
#include <bits/stdc++.h>
using namespace std;

int N;

int Solve()
{
    int cnt = 0;

    while (N >= 5)
    {
        cnt += N / 5;
        N = N / 5;
    }

    return cnt;
}

int main()
{
    cin >> N;
    cout << Solve();
}
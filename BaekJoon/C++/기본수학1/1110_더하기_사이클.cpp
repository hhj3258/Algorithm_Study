#include <bits/stdc++.h>
using namespace std;

void Solve(int n)
{
    string strN = "";
    if (n < 10)
        strN = "0";
    strN += to_string(n);

    const string originN = strN;

    int newN;
    int cnt = 0;
    do
    {
        newN = strN[0] - '0' + strN[1] - '0';

        string newStrN = to_string(newN);

        strN = strN[1] + newStrN[newStrN.size() - 1];

        cnt++;
    } while (strN != originN);

    cout << cnt;
}

int main()
{
    int n;
    cin >> n;
    Solve(n);
}
#include <bits/stdc++.h>
using namespace std;

void Solve(string &ps)
{
    int cnt = 0;
    int isVPS = true;
    for (int i = 0; i < ps.size(); i++)
    {
        if (cnt < 0)
        {
            isVPS = false;
            break;
        }

        if (ps[i] == '(')
            cnt++;
        else
            cnt--;
    }

    if (isVPS && cnt == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int T;
    cin >> T;

    string ps;
    for (int i = 0; i < T; i++)
    {
        cin >> ps;
        Solve(ps);
    }
}
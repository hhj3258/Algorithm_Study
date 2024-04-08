#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int card;
    unordered_map<int, int> cardMap;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        cardMap[card]++;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> card;
        cout << cardMap[card] << ' ';
    }
}
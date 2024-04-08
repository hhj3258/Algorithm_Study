#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int card;
    unordered_set<int> cardSet;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        cardSet.insert(card);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> card;

        auto it = cardSet.find(card);

        if (it != cardSet.end())
        {
            cout << 1 << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
}
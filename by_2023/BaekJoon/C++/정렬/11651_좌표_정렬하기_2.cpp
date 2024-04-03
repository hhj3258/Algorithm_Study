#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int N; //1<=N<=100,000
    cin >> N;

    int x, y;
    vector<pair<int, int>> Coordinates;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        Coordinates.push_back(make_pair(x, y));
    }

    sort(Coordinates.begin(), Coordinates.end(), cmp);

    for (int i = 0; i < Coordinates.size(); i++)
        cout << Coordinates[i].first << " " << Coordinates[i].second << '\n';
}
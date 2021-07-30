#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    sort(Coordinates.begin(), Coordinates.end());

    for (int i = 0; i < Coordinates.size(); i++)
        cout << Coordinates[i].first << " " << Coordinates[i].second << '\n';
}
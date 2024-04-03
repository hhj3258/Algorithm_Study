#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else
        return false;
}

void Solve(vector<pair<int, int>> end_time_sort)
{
    sort(end_time_sort.begin(), end_time_sort.end(), cmp);

    int confer = 0;
    int end_time = 0;

    for (int i = 0; i < N; i++)
    {
        if (end_time_sort[i].first >= end_time)
        {
            end_time = end_time_sort[i].second;
            confer++;
        }
    }

    cout << confer;
}

int main()
{
    cin >> N;
    vector<pair<int, int>> end_time_sort(N);

    for (int i = 0; i < N; i++)
        cin >> end_time_sort[i].first >> end_time_sort[i].second;

    Solve(end_time_sort);
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;

void Solve(vector<int> homes)
{
    sort(homes.begin(), homes.end());

    int left = 1;
    int right = homes.back() - homes.front();
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int set_num = 1;
        int idx = 0;
        for (int i = 1; i < N; i++)
        {
            int distance = homes[i] - homes[idx];

            if (distance >= mid)
            {
                set_num++;
                idx = i;
            }
        }

        if (set_num >= C)
        {
            left = mid + 1;
            if (mid > answer)
                answer = mid;
        }
        else if (set_num < C)
        {
            right = mid - 1;
        }
    }

    cout << answer;
}

int main()
{
    cin >> N >> C;
    vector<int> homes(N);
    for (int i = 0; i < N; i++)
        cin >> homes[i];

    Solve(homes);
}
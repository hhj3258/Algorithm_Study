#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    int M;
    cin >> M;

    int key;
    for (int i = 0; i < M; i++)
    {
        cin >> key;
        auto iter = lower_bound(nums.begin(), nums.end(), key);

        if (*iter == key)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
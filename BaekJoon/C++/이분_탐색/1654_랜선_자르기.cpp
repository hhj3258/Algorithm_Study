#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N;

void Solve(vector<int> lans)
{
    long long left = 1;
    long long right = *max_element(lans.begin(), lans.end());
    long long max_len = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for (int i = 0; i < lans.size(); i++)
        {
            cnt += lans[i] / mid;
        }

        if (cnt >= N)
        {
            left = mid + 1;
            if (mid > max_len)
                max_len = mid;
        }
        else if (cnt < N)
        {
            right = mid - 1;
        }
    }

    cout << max_len;
}

int main()
{
    cin >> K >> N;
    vector<int> lans(K);
    for (int i = 0; i < K; i++)
        cin >> lans[i];
    Solve(lans);
}
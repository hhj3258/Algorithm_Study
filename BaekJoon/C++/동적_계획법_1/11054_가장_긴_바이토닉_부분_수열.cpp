#include <iostream>
#include <vector>
using namespace std;

int N;

void Solve(vector<int> nums, vector<int> &dp)
{
    int maxV = 1;
    int idx = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);

            if (dp[i] > maxV)
            {
                maxV = dp[i];
                idx = i;
            }
        }
    }
}

int main()
{
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    vector<int> inc_dp(N, 1);
    Solve(nums, inc_dp);

    vector<int> tempVec = nums;
    for (int i = 0; i < N; i++)
        nums[i] = tempVec[N - 1 - i];

    vector<int> dec_dp(N, 1);
    Solve(nums, dec_dp);

    vector<int> temp2 = dec_dp;
    for (int i = 0; i < N; i++)
        dec_dp[i] = temp2[N - i - 1];

    int maxV = -1;
    for (int i = 0; i < N; i++)
    {
        int tempV = inc_dp[i] + dec_dp[i] - 1;
        if (maxV < tempV)
            maxV = tempV;
    }

    cout << maxV;
}
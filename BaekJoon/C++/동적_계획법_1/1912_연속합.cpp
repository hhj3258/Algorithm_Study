#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[100001];

void Solve(vector<int> nums)
{
    dp[0] = nums[0];
    int maxV = dp[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(nums[i] + dp[i - 1], nums[i]);

        if (dp[i] > maxV)
            maxV = dp[i];
    }

    cout << maxV;
}

int main()
{
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    Solve(nums);
}
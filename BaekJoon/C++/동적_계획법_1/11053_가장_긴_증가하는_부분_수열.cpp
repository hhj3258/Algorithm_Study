#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp(1001, 1);
int nums[1001];

void Solve()
{
    int maxV = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);

                if (dp[i] > maxV)
                    maxV = dp[i];
            }
        }
    }

    cout << maxV;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    Solve();
}
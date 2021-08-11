#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void Solve(vector<int> credit, vector<int> dp)
{
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = credit[i]; j <= M; j++)
        {
            if (dp[j - credit[i]] != 10001)
            {
                cout << j - credit[i] << ": " << dp[j - credit[i]] << endl;

                dp[j] = min(dp[j], dp[j - credit[i]] + 1);
                cout << j << ":: " << dp[j] << endl;
            }
        }
    }

    if (dp[M] == 10001)
        cout << -1 << endl;
    else
        cout << dp[M] << endl;
}

int main()
{
    N = 2;
    M = 15;

    vector<int> credit(N);
    vector<int> dp(M + 1, 10001);
    credit[0] = 2;
    credit[1] = 3;
    // for (int i = 0; i < N; i++)
    //     cin >> credit[i];

    sort(credit.begin(), credit.end());

    Solve(credit, dp);
}
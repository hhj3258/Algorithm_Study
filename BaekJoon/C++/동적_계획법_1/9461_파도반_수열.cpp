#include <iostream>
#include <vector>
using namespace std;

long long dp[102] = {
    0,
    1,
    1,
    1,
};

long long Solve(int N)
{
    for (int i = 4; i <= N; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    return dp[N];
}

int main()
{
    int T, N;
    cin >> T;

    vector<long long> result(T);
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        result[i] = Solve(N);
    }

    for (long long i : result)
        cout << i << '\n';
}
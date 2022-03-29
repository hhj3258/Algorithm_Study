#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number)
{
    int answer = -1;

    vector<unordered_set<int>> dp(9);

    // 1) N, NN, NNN ...
    int n = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        n = 10 * n + N;
        dp[i].insert(n);
    }

    // i = N의 갯수
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            // cout << "<i> = " << i << "\t\t";
            // cout << "j: " << j << ' ';
            // cout << "i - j: " << i - j << endl;

            for (int a : dp[j])
            {
                for (int b : dp[i - j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b > 0)
                        dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].find(number) != dp[i].end())
        {
            // for (auto it = dp[i].begin(); it != dp[i].end(); ++it)
            // {
            //     cout << (*it) << endl;
            // }
            answer = i;
            return answer;
        }
    }

    return answer;
}

int main()
{
    int N, number;
    cin >> N >> number;
    cout << solution(N, number);
}
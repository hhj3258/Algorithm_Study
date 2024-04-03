#include <iostream>
#include <vector>

using namespace std;

int N, K;

void Solve(vector<int> coins)
{
    int answer = 0;

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        int insert_coins = K / coins[i];
        answer += insert_coins;
        K = K % coins[i];

        if (K == 0)
            break;
    }

    cout << answer;
}

int main()
{
    cin >> N >> K;
    vector<int> coins(N);
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    Solve(coins);
}
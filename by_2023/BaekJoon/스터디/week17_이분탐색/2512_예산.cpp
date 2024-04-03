#include <bits/stdc++.h>

using namespace std;

void Solve(int N, int M, int maxV, int minV, const vector<int> &citys)
{
    int answer = 0;
    while (minV <= maxV)
    {
        int mid = (minV + maxV) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum += min(citys[i], mid);
        }

        if (sum > M)
        {
            maxV = mid - 1;
        }
        else
        {
            answer = mid;
            minV = mid + 1;
        }
    }

    cout << answer;
}

int main()
{
    int N;
    cin >> N;
    vector<int> citys(N);
    int maxV = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> citys[i];
        maxV = max(maxV, citys[i]);
    }

    int M;
    cin >> M;

    Solve(N, M, maxV, 0, citys);
}
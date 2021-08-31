#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

void Solve()
{
    int left = 1;
    int right = K;

    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        long long cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            // mid/i = i 행에서 mid보다 작은 j의 갯수
            // mid/i > N 가 될 경우가 있으므로 mid/i와 N중 작은 것
            cnt += min(mid / i, N);
        }

        if (cnt >= K)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer;
}

int main()
{
    cin >> N >> K;
    Solve();
}
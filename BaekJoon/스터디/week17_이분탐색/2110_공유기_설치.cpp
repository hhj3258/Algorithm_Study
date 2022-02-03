#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Solve(vector<int> &houses, int N, int C)
{
    int answer = 0;
    int minDist = 1;
    int maxDist = houses[N - 1] - houses[0];

    while (minDist <= maxDist)
    {
        int mid = (minDist + maxDist) / 2;

        // 공유기 설치 갯수
        int cnt = 1;
        // 직전에 공유기를 설치한 집
        int prevHouse = houses[0];
        for (int i = 1; i < N; i++)
        {
            // 지금 설치할 집과 직전에 설치한 집의 거리 차이 >= 현재 최소 거리 라면
            if (houses[i] - prevHouse >= mid)
            {
                // 공유기 설치 수 + 1
                cnt++;
                // 직전 설치한 집 갱신
                prevHouse = houses[i];
            }
        }

        // 공유기가 요구 수보다 많거나 같다면
        if (cnt >= C)
        {
            // 현재 최대로 긴 최소 거리 갱신
            answer = mid;
            // 최소 거리를 늘려서 다시 수행
            minDist = mid + 1;
        }
        // 공유기가 요구 수보다 적다면
        else
        {
            // 최소 거리를 줄여서 다시 수행
            maxDist = mid - 1;
        }
    }

    cout << answer;
}

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++)
        cin >> houses[i];

    sort(houses.begin(), houses.end());

    Solve(houses, N, C);
}
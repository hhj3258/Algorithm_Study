#include <bits/stdc++.h>
using namespace std;

int N, M;
int in_nums[10001];
int nums[10001];

void Solve(int cnt, int idx)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << nums[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = idx; i < N; i++)
    {
        nums[cnt] = in_nums[i];
        Solve(cnt + 1, i + 1);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> in_nums[i];

    sort(in_nums, in_nums + N);

    Solve(0, 0);
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[9];
int in_nums[10001];
int visited[10001];

void Solve(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << nums[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;

            nums[cnt] = in_nums[i];
            Solve(cnt + 1);

            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> in_nums[i];

    sort(in_nums, in_nums + N);

    Solve(0);
}
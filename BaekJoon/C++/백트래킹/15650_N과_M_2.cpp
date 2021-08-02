#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(int cnt, int num, vector<int> vec)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << vec[i] << ' ';

        cout << '\n';
        return;
    }

    for (int i = num; i < N; i++)
    {
        vec[cnt] = i + 1;
        dfs(cnt + 1, i + 1, vec);
    }
}

int main()
{
    cin >> N >> M;
    vector<int> vec(N);
    vector<bool> visited(N);

    dfs(0, 0, vec);
}
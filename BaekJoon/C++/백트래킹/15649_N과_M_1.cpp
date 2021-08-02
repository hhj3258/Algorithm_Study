#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(int cnt, vector<int> vec, vector<bool> visited)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << vec[i] << ' ';

        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            vec[cnt] = i + 1;
            dfs(cnt + 1, vec, visited);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    vector<int> vec(N);
    vector<bool> visited(N, 0);
    dfs(0, vec, visited);
}
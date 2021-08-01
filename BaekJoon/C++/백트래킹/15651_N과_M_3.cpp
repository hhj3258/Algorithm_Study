#include <iostream>
#include <vector>

using namespace std;

int N, M;

void DFS(int cnt, vector<int> vec, vector<bool> visited)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << vec[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        vec[cnt] = i + 1;
        DFS(cnt + 1, vec, visited);
    }
}

int main()
{
    cin >> N >> M;
    vector<int> vec(N);
    vector<bool> visited(N);
    DFS(0, vec, visited);
}
#include <iostream>
#include <vector>
using namespace std;

int N; // 1 ¡Â N < 15
int answer = 0;

vector<vector<bool>> Visit(vector<vector<bool>> visited, int i, int j)
{
    visited[i][j] = true;

    for (int n = 1; i + n < N; n++)
    {
        visited[i + n][j] = true;

        if (j + n < N)
            visited[i + n][j + n] = true;

        if (j - n >= 0)
            visited[i + n][j - n] = true;
    }

    return visited;
}

void N_Queen(int qCnt, vector<vector<bool>> visited)
{
    if (qCnt == N)
    {
        answer++;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (visited[qCnt][j])
            continue;

        N_Queen(qCnt + 1, Visit(visited, qCnt, j));
    }
}

int main()
{
    cin >> N;

    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N
    N_Queen(0, visited);

    cout << answer;
}
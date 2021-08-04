#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 1 ≤ N < 15
int answer;

void Visit(vector<vector<bool>> &visited, int i, int j)
{
    //가로축
    for (int k = 0; k < N; k++)
    {
        visited[i][k] = true;
        visited[k][j] = true;
    }

    // 대각축(\)
    for (int n = 0;; n++)
    {
        if (i + n < N)
        {
            if (j + n < N)
                visited[i + n][j + n] = true;

            if (j - n >= 0)
                visited[i + n][j - n] = true;
        }
        else
            break;
    }
}

void N_Queen(int qCnt, vector<vector<bool>> visited, int x)
{
    if (qCnt == N)
    {
        answer++;
        cout << answer << ' ';
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                vector<vector<bool>> temp = visited;
                Visit(visited, i, j);
                N_Queen(qCnt + 1, visited, i + 1);
                visited = temp;
            }
        }
    }
}

int main()
{
    cin >> N;
    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N

    N_Queen(0, visited, 0);

    cout << answer << endl;
}
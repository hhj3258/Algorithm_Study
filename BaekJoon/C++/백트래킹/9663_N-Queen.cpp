#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 1 ≤ N < 15
int answer = 0;

void TVisite(vector<vector<bool>> &visited, int i, int j)
{
    //가로축
    for (int k = 0; k < N; k++)
        visited[i][k] = true;
    //세로축
    for (int k = 0; k < N; k++)
        visited[k][j] = true;
    // 대각축(\)
    int min_v = min(i, j);
    int max_v = -1;
    for (int n = min_v; max_v < N - 1; n--)
    {
        visited[i - n][j - n] = true;
        max_v = max(i - n, j - n);
    }
    // 대각축(/)
    for (int n = 0;; n++)
    {
        visited[i - n][j + n] = true;
        if (i - n == 0 || j + n == N - 1)
            break;
    }
    for (int n = 0;; n++)
    {
        visited[i + n][j - n] = true;
        if ((i + n) == (N - 1) || (j - n) == 0)
            break;
    }
}

void FVisite(vector<vector<bool>> &visited, int i, int j)
{
    //가로축
    for (int k = 0; k < N; k++)
        visited[i][k] = false;
    //세로축
    for (int k = 0; k < N; k++)
        visited[k][j] = false;
    // 대각축(\)
    int min_v = min(i, j);
    int max_v = -1;
    for (int n = min_v; max_v < N - 1; n--)
    {
        visited[i - n][j - n] = false;
        max_v = max(i - n, j - n);
    }
    // 대각축(/)
    for (int n = 0;; n++)
    {
        visited[i - n][j + n] = false;
        if (i - n == 0 || j + n == N - 1)
            break;
    }
    for (int n = 0;; n++)
    {
        visited[i + n][j - n] = false;
        if ((i + n) == (N - 1) || (j - n) == 0)
            break;
    }
}

int depth = 0;

void N_Queen(int qCnt, vector<vector<bool>> visited, int x, int y)
{
    cout << "qCnt: " << qCnt << endl;
    if (qCnt == N - 1)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                TVisite(visited, i, j);
                /*
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        cout << visited[i][j] << ' ';
                    }
                    cout << '\n';
                }

                cout << "[" << i << ", " << j << "]" << endl;
                cout << "now count: "
                     << ++count << endl;
                */
                cout << "depth: " << ++depth << endl;
                cout << i << ' ' << j << endl;
                //cout << visited[i][j] << endl;

                N_Queen(qCnt + 1, visited, i, j);

                cout << "depth: " << --depth << endl;
                FVisite(visited, i, j);
            }
        }
    }
}

int main()
{
    cin >> N;
    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N

    N_Queen(0, visited, 0, 0);

    cout << "answer: " << answer << endl;
}
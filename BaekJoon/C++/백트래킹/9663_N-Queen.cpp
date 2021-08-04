#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 1 ≤ N < 15

vector<vector<bool>> TVisit(vector<vector<bool>> visited, int i, int j)
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

    return visited;
}

int depth = 0;
int answer = 0;

void N_Queen(int qCnt, vector<vector<bool>> visited, int x, int y)
{
    // cout << "xy[" << x << ", " << y << "]" << endl;
    // cout << "qCnt: " << qCnt << endl;
    if (qCnt == N)
    {
        answer++;
        cout << answer << ' ';
        //      << endl;
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                // cout << "chk: " << i << " " << j << endl
                //      << endl;
                vector<vector<bool>> temp = visited;
                visited = TVisit(visited, i, j);
                N_Queen(qCnt + 1, visited, i, j);
                visited = temp;
            }
        }
    }
}

int main()
{
    cin >> N;
    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;

    N_Queen(0, visited, 0, 0);

    cout << answer << endl;
}
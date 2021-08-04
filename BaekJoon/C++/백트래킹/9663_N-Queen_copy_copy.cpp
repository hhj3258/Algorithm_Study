#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int N; // 1 ¡Â N < 15
int answer = 0;
int cnt = 0;

bool Check(vector<vector<bool>> visited, int i, int j)
{
    for (int n = 1; i - n >= 0; n++)
    {
        //cout << j - n << endl;
        if (visited[i][j] == visited[i - n][j])
            return 0;

        if (j - n >= 0)
        {
            if (visited[i][j] == visited[i - n][j - n])
                return 0;
        }

        if (j + n < N)
        {
            if (visited[i][j] == visited[i - n][j + n])
                return 0;
        }
    }

    return 1;
}

void N_Queen(int qCnt, vector<vector<bool>> visited)
{
    if (qCnt == N)
    {
        answer++;
        //cout << endl;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        visited[qCnt][j] = true;

        if (Check(visited, qCnt, j))
        {
            //cout << "[" << qCnt << " " << j << "]\n";
            N_Queen(qCnt + 1, visited);
        }

        visited[qCnt][j] = false;
    }
}

int main()
{
    cin >> N;

    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N
    N_Queen(0, visited);

    cout << "answer: " << answer << endl;
}
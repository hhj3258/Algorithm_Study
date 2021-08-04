#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int N; // 1 ¡Â N < 15
int answer = 0;
int cnt = 0;
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

time_t s, e;
int sum = 0;
vector<int> nowQs(15, -1);
void N_Queen(int qCnt, vector<vector<bool>> visited)
{
    if (qCnt == N)
    {
        answer++;
        // cout << "[ ";
        // for (int i = 0; i < N; i++)
        //     cout << nowQs[i] << ' ';
        // cout << "]\n";

        // cout << answer << " \n";
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (visited[qCnt][j])
            continue;

        s = clock();

        N_Queen(qCnt + 1, Visit(visited, qCnt, j));

        e = clock();
        sum += e - s;
    }
}

int main()
{
    cin >> N;
    time_t start = clock();

    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N
    N_Queen(0, visited);
    cout << endl
         << answer << endl;
    time_t end = clock();
    double result_time = (double)(end - start);
    cout << "time: " << result_time << " ms\n";
    cout << "sum: " << sum << endl;
}
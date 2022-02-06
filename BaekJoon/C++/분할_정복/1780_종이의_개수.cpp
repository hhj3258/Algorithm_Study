#include <iostream>
#include <vector>
using namespace std;

int answer[3] = {0};

bool DivideCheck(const vector<vector<int>> &paper, int y, int x, int length)
{
    int setColor = paper[y][x];

    for (int i = y; i < y + length; i++)
        for (int j = x; j < x + length; j++)
            if (paper[i][j] != setColor)
                return true;

    return false;
}

void Solve(const vector<vector<int>> &paper, int y, int x, int length)
{
    if (DivideCheck(paper, y, x, length) == true)
    {
        int nextLength = length / 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int nextY = y + nextLength * i;
                int nextX = x + nextLength * j;

                Solve(paper, nextY, nextX, nextLength);
            }
        }
    }
    else
    {
        answer[paper[y][x]]++;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    int temp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            paper[i][j] = temp + 1;
        }

    Solve(paper, 0, 0, N);

    for (int cnt : answer)
        cout << cnt << '\n';
}
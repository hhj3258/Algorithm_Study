#include <iostream>
using namespace std;

int N; //4 ? N ? 20, N? ??
int param[20][20];
int minV = 1000000000;
bool check[20];
bool endFlag = false;

void TeamBuilding(int cnt, int num)
{
    if (cnt == N / 2)
    {
        int start = 0;
        int link = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (check[i] && check[j])
                    start += param[i][j];
                if (!check[i] && !check[j])
                    link += param[i][j];
            }
        }

        if (abs(start - link) < minV)
            minV = abs(start - link);

        if (minV == 0)
            endFlag = true;

        return;
    }

    for (int i = num; i < N; i++)
    {
        check[i] = true;
        TeamBuilding(cnt + 1, i + 1);
        check[i] = false;

        if (endFlag)
            return;
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> param[i][j];

    TeamBuilding(0, 0);

    cout << minV;
}
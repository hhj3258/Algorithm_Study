#include <bits/stdc++.h>
using namespace std;

enum EHuman
{
    Blank = 0,
    Student = 1,
    Sunggu = 2,
    Professor = 5,
};

struct Point
{
    int y;
    int x;
};

double GetDist(int x1, int y1, int x2, int y2)
{
    double a = pow((x1 - x2), 2);
    double b = pow((y1 - y2), 2);
    return sqrt(a + b);
}

int Solve(vector<vector<int>> &input, Point professor_pos, Point sunggu_pos)
{
    int dist = GetDist(professor_pos.y, professor_pos.x, sunggu_pos.y, sunggu_pos.x);
    if (dist < 5)
    {
        return 0;
    }

    Point left_upper;
    left_upper.y = min(professor_pos.y, sunggu_pos.y);
    left_upper.x = min(professor_pos.x, sunggu_pos.x);
    Point right_down;
    right_down.y = max(professor_pos.y, sunggu_pos.y);
    right_down.x = max(professor_pos.x, sunggu_pos.x);

    int student_cnt = 0;
    for (int y = left_upper.y; y <= right_down.y; y++)
    {
        for (int x = left_upper.x; x <= right_down.x; x++)
        {
            if (input[y][x] == Student)
            {
                student_cnt++;
            }
        }
    }

    if (student_cnt >= 3)
        return 1;
    else
        return 0;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> input(N, vector<int>(N));
    Point professor_pos, sunggu_pos;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input[i][j];

            if (input[i][j] == Professor)
            {
                professor_pos.y = i;
                professor_pos.x = j;
            }
            if (input[i][j] == Sunggu)
            {
                sunggu_pos.y = i;
                sunggu_pos.x = j;
            }
        }
    }

    int answer = Solve(input, professor_pos, sunggu_pos);

    cout << answer;
}
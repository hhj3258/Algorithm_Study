#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int x_max = 0;
    int y_max = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        int x_size = sizes[i][0];
        int y_size = sizes[i][1];

        if (x_size < y_size)
            swap(x_size, y_size);

        x_max = max(x_max, x_size);
        y_max = max(y_max, y_size);
    }

    answer = x_max * y_max;

    return answer;
}
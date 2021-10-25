#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Solve(vector<vector<int>> triangle)
{
    int upLeft, upRight;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j > 0)
                upLeft = triangle[i - 1][j - 1];
            else
                upLeft = 0;

            if (j < triangle[i - 1].size())
                upRight = triangle[i - 1][j];
            else
                upRight = 0;

            triangle[i][j] += max(upLeft, upRight);
        }
    }

    return triangle;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);

    int num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> num;
            triangle[i].push_back(num);
        }
    }

    triangle = Solve(triangle);

    int result = 0;
    for (int i = 0; i < triangle[n - 1].size(); i++)
        result = max(result, triangle[n - 1][i]);

    cout << result;
}
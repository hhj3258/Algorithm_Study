#include <iostream>
#include <vector>
using namespace std;

int dp[55][55][55];

struct abc
{
    int a, b, c;
};

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        if (dp[a][b][c] == 0)
            dp[a][b][c] = w(20, 20, 20);
        return dp[a][b][c];
    }
    if (a < b && b < c)
    {
        if (dp[a][b][c] == 0)
            dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }

    if (dp[a][b][c] == 0)
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return dp[a][b][c];
}

int main()
{
    vector<abc> input;

    abc temp;
    while (true)
    {
        cin >> temp.a >> temp.b >> temp.c;
        if (temp.a == -1 && temp.b == -1 && temp.c == -1)
            break;
        input.push_back(temp);
    }

    int result;
    for (int i = 0; i < input.size(); i++)
    {
        result = w(input[i].a, input[i].b, input[i].c);
        cout << "w(" << input[i].a << ", " << input[i].b << ", " << input[i].c << ") = " << result << '\n';
    }
}
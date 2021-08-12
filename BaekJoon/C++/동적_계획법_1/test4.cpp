#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    int n, m;
    cin >> T >> n >> m;

    vector<vector<int>> gold(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> gold[i][j];

    for (int j = 0; j < m - 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
                gold[i][j + 1] += max(gold[i][j], gold[1][j]);
            else
                gold[i][j + 1] += max(gold[0][j], max(gold[1][j], gold[2][j]));
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, gold[i][m - 1]);
    }

    cout << result << endl;
}
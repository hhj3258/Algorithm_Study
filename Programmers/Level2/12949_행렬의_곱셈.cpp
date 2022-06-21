#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    // (n * m) * (m * r) = (n * r)
    // ( arr1.size() * arr1[0].size() ) * ( arr2.size() * arr2[0].size() ) = ( arr1.size() * arr2[0].size() )

    int n = arr1.size();
    int m = arr2.size();
    int r = arr2[0].size();

    vector<vector<int>> answer(n, vector<int>(r));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int ai = 0; ai < m; ai++)
            {
                answer[i][j] += arr1[i][ai] * arr2[ai][j];
            }
        }
    }

    return answer;
}
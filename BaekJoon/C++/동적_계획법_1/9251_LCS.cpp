#include <iostream>
#include <vector>
using namespace std;

string str1, str2;

void Solve()
{
    //공백(0)인 행과 열을 한 개씩 추가해야 함
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));

    //공백인 행과 열을 건너뛰고 i=1,j=1부터 시작
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            //(i-1)과 (j-1) 번째 문자가 서로 같다면 -> 공백인 행과 열이 있으므로 문자열에 -1씩 오프셋을 줘야 맞음
            if (str1[i - 1] == str2[j - 1])
                //dp[i][j] = (i-1, j-1)값에 +1 한 값으로 갱신
                dp[i][j] = dp[i - 1][j - 1] + 1;
            //같지 않다면
            else
                //dp[i][j] = 위와 왼쪽 값 중 큰 값으로 갱신
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    cout << dp[str1.size()][str2.size()];
}

int main()
{
    cin >> str1 >> str2;

    Solve();
}
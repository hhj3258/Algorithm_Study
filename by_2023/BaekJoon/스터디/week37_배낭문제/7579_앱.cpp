#include <iostream>
#include <vector>
using namespace std;

int N, M;

// M 바이트 이상의 메모리 확보하기 위한 '최소'비용
void Solve(vector<vector<int>>& dp, vector<pair<int, int>>& apps, int sum)
{
	for (int i = 1; i <= N; i++)
	{
		int byte = apps[i].first;
		int cost = apps[i].second;

		for (int j = 0; j <= sum; j++)
		{
			if (cost > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + byte);
		}
	}
}

int main()
{
	// N개의 앱, M바이트 확보 필요
	cin >> N >> M;

	vector<pair<int, int>> apps(N + 1);

	// Weight: 앱들이 사용중인 바이트 수
	for (int i = 1; i <= N; i++)
	{
		cin >> apps[i].first;
	}

	// Value: 앱을 비활성화 할 경우 비용
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> apps[i].second;
		sum += apps[i].second;
	}

	vector<vector<int>> dp(N + 1, vector<int>(sum + 1));

	Solve(dp, apps, sum);

	for (int i = 0; i <= sum; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i;
			break;
		}
	}
}
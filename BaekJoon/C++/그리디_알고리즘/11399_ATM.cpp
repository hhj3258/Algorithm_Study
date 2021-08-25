#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
    cin >> N;
    vector<int> timeVec(N);

    for (int i = 0; i < N; i++)
        cin >> timeVec[i];

    sort(timeVec.begin(), timeVec.end());

    vector<int> sumVec(N);
    sumVec[0] = timeVec[0];
    int answer = sumVec[0];

    for (int i = 1; i < N; i++)
    {
        sumVec[i] = timeVec[i] + sumVec[i - 1];
        answer += sumVec[i];
    }

    cout << answer;
}

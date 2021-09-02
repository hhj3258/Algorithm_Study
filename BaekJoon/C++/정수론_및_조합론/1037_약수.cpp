#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void Solve(vector<int> divisor)
{
    sort(divisor.begin(), divisor.end());
    int answer = divisor.front() * divisor.back();

    cout << answer;
}

int main()
{
    cin >> N;
    vector<int> divisor(N);
    for (int i = 0; i < N; i++)
        cin >> divisor[i];

    Solve(divisor);
}
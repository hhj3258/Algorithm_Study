#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void Solve(vector<long long> tree)
{
    sort(tree.begin(), tree.end());

    long long left = 0;            //절단기 최소
    long long right = tree.back(); //나무 최대길이

    long long answer = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long now_m = 0;
        for (int i = 0; i < tree.size(); i++)
        {
            long long temp = tree[i] - mid;
            if (temp > 0)
                now_m += temp;
        }

        if (now_m >= M)
        {
            left = mid + 1;
            answer = max(answer, mid);
                }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer;
}

int main()
{
    cin >> N >> M;
    vector<long long> tree(N);
    for (int i = 0; i < N; i++)
        cin >> tree[i];

    Solve(tree);
}
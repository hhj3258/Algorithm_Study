#include <iostream>
#include <vector>
using namespace std;

long long arr[50] = {
    0,
    1,
};

long long fibo(int N)
{
    if (N == 0 || N == 1)
    {
        return arr[N];
    }
    else if (arr[N] == 0)
    {
        arr[N] = fibo(N - 1) + fibo(N - 2);
    }

    return arr[N];
}

int main()
{
    int T, N;
    cin >> T;

    vector<pair<long long, long long>> answer;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        if (N == 0)
            answer.push_back(make_pair(1, 0));
        else
            answer.push_back(make_pair(fibo(N - 1), fibo(N)));
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i].first << ' ' << answer[i].second << '\n';
}
#include <iostream>
#include <string>

using namespace std;

int SumCalc(const int &num)
{
    int sum = num;
    string num_str = to_string(num);
    for (int i = 0; i < num_str.size(); i++)
    {
        sum += num_str[i] - '0';
    }

    return sum;
}

void Solve(int N)
{
    int digit = to_string(N).size();
    // N = K + (k1 + k2 + k3)
    // K = N - (k1 + k2 + k3)
    // 각 자릿수(k1, k2, k3)의 최고값 = 9
    // (최소)K = N - 9 * 3
    int min_num = N - 9 * digit;

    int answer = 0;
    while (min_num <= N)
    {
        int now_sum = SumCalc(min_num);

        if (now_sum == N)
        {
            answer = min_num;
            break;
        }

        min_num++;
    }

    cout << answer;
}

int main()
{
    int N;
    cin >> N;

    Solve(N);
}
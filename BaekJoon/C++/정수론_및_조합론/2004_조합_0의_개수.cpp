#include <iostream>
using namespace std;

// int n ==> n! 을 가리킴
// n! 의 2의 승수의 개수를 구함
long CountPowTwo(int n)
{
    long cnt = 0;
    while (n >= 2)
    {
        cnt += n / 2;
        n = n / 2;
    }

    return cnt;
}

long CountPowFive(int n)
{
    long cnt = 0;
    while (n >= 5)
    {
        cnt += n / 5;
        n = n / 5;
    }

    return cnt;
}

void Solve(int n, int m)
{
    long pow2_cnt = CountPowTwo(n) - CountPowTwo(n - m) - CountPowTwo(m);
    long pow5_cnt = CountPowFive(n) - CountPowFive(n - m) - CountPowFive(m);

    // 2^a 와 5^b 에서 a,b 중 작은 값을 출력(2*5의 짝의 갯수)
    cout << min(pow2_cnt, pow5_cnt);
}

int main()
{
    int N, M;
    cin >> N >> M;
    Solve(N, M);
}
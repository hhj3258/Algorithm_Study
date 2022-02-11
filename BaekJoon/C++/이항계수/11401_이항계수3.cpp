#include <bits/stdc++.h>
using namespace std;
#define long long long

const long C = 1000000007;

long dp[4000000];

long Factorial(long n)
{
    if (dp[n] != 0)
        return dp[n];

    if (n <= 1)
        return dp[n] = 1;

    return dp[n] = n * Factorial(n - 1) % C;
}

long pow(long base, long exp)
{
    if (exp == 0)
        return 1;

    long temp = pow(base, exp / 2);
    temp = temp * temp % C;

    if (exp % 2 == 1)
        return temp * base % C;
    else
        return temp;
}

void Solve(long N, long K)
{
    // 분자 N!
    long upper = Factorial(N);

    // 분모 (K! * (N-K)!) mod p
    long down = Factorial(K) * Factorial(N - K) % C;

    // N! * 분모의 역원((K! * (N-K)!)
    cout << (upper * pow(down, C - 2)) % C;
}

int main()
{
    long N, K;
    cin >> N >> K;

    Solve(N, K);
}
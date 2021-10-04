#include <iostream>
#include <vector>
using namespace std;

vector<bool> IsPrime(int N);

int main()
{
    int N;
    cin >> N;

    vector<bool> isPrime = IsPrime(N);

    if (N == 1)
    {
    }
    else if (isPrime[N])
    {
        cout << N;
    }
    else
    {
        int temp = N;
        do
        {
            for (int i = 0; i < isPrime.size(); i++)
            {
                if (isPrime[i])
                {
                    if (temp % i == 0)
                    {
                        cout << i << endl;
                        temp = temp / i;
                        break;
                    }
                }
            }
        } while (!isPrime[temp]);
        cout << temp;
    }
}

vector<bool> IsPrime(int N)
{
    vector<bool> primes(N, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (primes[i])
            for (int j = i * i; j <= N; j += i)
            {
                primes[j] = false;
            }
    }

    return primes;
}
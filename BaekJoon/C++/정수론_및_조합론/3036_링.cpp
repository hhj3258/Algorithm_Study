#include <iostream>
#include <vector>
using namespace std;

int N;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void Solve(vector<int> rings)
{
    int main_ring = rings[0];

    for (int i = 1; i < N; i++)
    {
        int gcd = GCD(main_ring, rings[i]);
        cout << main_ring / gcd << '/' << rings[i] / gcd << endl;
    }
}

int main()
{
    cin >> N;
    vector<int> rings(N);
    for (int i = 0; i < N; i++)
        cin >> rings[i];

    Solve(rings);
}
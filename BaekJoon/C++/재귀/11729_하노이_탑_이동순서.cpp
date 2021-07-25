#include <cstdio>
using namespace std;

void Hanoi(int n, int from, int by, int to)
{
    if (n == 0)
        return;
    else
    {
        Hanoi(n - 1, from, to, by);
        printf("%d %d\n", from, to);
        Hanoi(n - 1, by, from, to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    Hanoi(n, 1, 2, 3);
}
#include <iostream>
using namespace std;

void Stars(int i, int j, int n)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    {
        cout << ' ';
    }
    else
    {
        if (n / 3 == 0)
            cout << '*';
        else
            Stars(i, j, n / 3);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Stars(i, j, n);
        }
        cout << endl;
    }
}

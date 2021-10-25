#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;

    while (true)
    {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0)
            break;

        if (n1 < n2)
        {
            int mod = n2 % n1;
            if (mod == 0)
                cout << "factor\n";
            else
                cout << "neither\n";
        }
        else
        {
            int mod = n1 % n2;
            if (mod == 0)
                cout << "multiple\n";
            else
                cout << "neither\n";
        }
    }
}
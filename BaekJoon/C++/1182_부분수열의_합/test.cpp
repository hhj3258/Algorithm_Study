#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40};

    for (int i = 1; i < (1 << vec.size()); i++)
    {
        cout << "i " << bitset<4>(i) << "(" << i << "): ";
        for (int j = 0; j < vec.size(); j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << bitset<4>(1 << j) << "(" << vec[j] << "), ";
            }
        }
        cout << "\n\n";
    }
}
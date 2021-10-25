#include <iostream>
#include <vector>
using namespace std;

void AscendingSort(vector<int> vec_n)
{
    for (int i = vec_n.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec_n[j] > vec_n[j + 1])
            {
                int temp = vec_n[j];
                vec_n[j] = vec_n[j + 1];
                vec_n[j + 1] = temp;
            }
        }
    }

    for (int i : vec_n)
        cout << i << endl;
}

int main()
{
    int t;
    cin >> t;

    vector<int> vec_n;
    int temp;
    for (int i = 0; i < t; i++)
    {
        cin >> temp;
        vec_n.push_back(temp);
    }

    AscendingSort(vec_n);
}
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<int> v1, v2;

void merge(int left, int right)
{
    int mid = (left + right) / 2;
    int L = left;
    int R = mid + 1;
    int K = left;

    while (L <= mid && R <= right)
    {
        if (v1[L] < v1[R])
        {
            v2[K++] = v1[L++];
        }
        else
        {
            v2[K++] = v1[R++];
        }
    }

    int min_idx = K < mid ? K : R;

    while (min_idx <= right)
    {
        v2[K++] = v1[min_idx++];
    }

    for (int i = left; i <= right; i++)
        v1[i] = v2[i];
}

void partition(int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;
    partition(left, mid);
    partition(mid + 1, right);
    merge(left, right);
}

int main()
{
    int n;

    srand((unsigned int)time(NULL));

    cout << "[input]" << endl;
    for (int i = 0; i < 10; i++)
    {
        n = rand() % 10;
        cout << n << " ";

        v1.push_back(n);
        v2.push_back(0);
    }
    cout << endl
         << endl;

    cout << "[output]" << endl;
    partition(0, v1.size() - 1);

    for (int i = 0; i < 10; i++)
        cout << v1[i] << " ";
}
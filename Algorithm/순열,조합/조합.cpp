#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> datas, vector<int> temp, int index, int n, int r, int depth = 0)
{
    // depth == r 즉, temp의 원소가 r개만큼 찼다는 뜻
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << temp[i] << ' ';
        }
        cout << endl;

        return;
    }

    for (int i = index; i < n; i++)
    {
        temp[depth] = datas[i];
        combination(datas, temp, i + 1, n, r, depth + 1);
    }
}

long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    vector<int> datas;
    for (int i = 0; i < 8; i++)
        datas.push_back(i);
    int n = datas.size();
    int r = 4;
    combination(datas, vector<int>(r), 0, n, r);

    long long numberOfCases = factorial(datas.size()) / (factorial(r) * factorial(n - r));
    cout << numberOfCases;
}
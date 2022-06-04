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

int main()
{
    vector<int> datas = {1, 2, 3, 4, 5};
    int n = datas.size();
    int r = 3;
    combination(datas, vector<int>(r), 0, n, r);
}
#include <bits/stdc++.h>
using namespace std;

// 순열
// n개의 데이터 중 r개의 순열
void permutation(const vector<int> &datas, vector<int> temp, vector<bool> visited, int n, int r, int depth = 0)
{
    if (depth == r)
    {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << ' ';
        cout << endl;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        temp[depth] = datas[i];
        permutation(datas, temp, visited, n, r, depth + 1);
        visited[i] = false;
    }
}

// STL : next_permutation
// 반드시 오름차순 정렬 상태여야 함.
void permutation2(vector<int> datas, int n, int r)
{
    do
    {
        for (int i = 0; i < r; i++)
            cout << datas[i] << ' ';
        cout << endl;

        reverse(datas.begin() + r, datas.end());

    } while (next_permutation(datas.begin(), datas.end()));
}

int factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    vector<int> datas = {1, 2, 3, 4, 5};
    int n = datas.size();
    int r = 3;

    // permutation(datas, vector<int>(r), vector<bool>(n), n, r);
    permutation2(datas, n, r);

    // 순열의 가짓수 : n! / (n-r)!
    cout << "case : " << factorial(n) / factorial(n - r) << endl;
}
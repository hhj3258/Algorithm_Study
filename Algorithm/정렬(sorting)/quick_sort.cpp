#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &vec, int left, int right)
{
    // 최악의 경우에서 성능 개선 : 좌측값과 중간값을 바꾼다.
    int mid = (left + right) / 2;
    swap(vec[mid], vec[left]);

    int pivot = left;

    while (left < right)
    {
        while (vec[right] >= vec[pivot] && left < right)
            right--;

        while (vec[left] <= vec[pivot] && left < right)
            left++;

        swap(vec[left], vec[right]);
    }

    swap(vec[pivot], vec[left]);

    return left;
}

void QuickSort(vector<int> &vec, int left, int right)
{
    // 범위지정이 잘못된 경우
    if (left >= right)
    {
        return;
    }

    int pivot = Partition(vec, left, right);

    // pivot 좌측
    QuickSort(vec, left, pivot - 1);
    // pivot 우측
    QuickSort(vec, pivot + 1, right);
}

int main()
{
    srand((unsigned int)time(0));

    vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.emplace_back(rand() % 10);
        cout << vec[i] << ' ';
    }
    cout << endl;

    QuickSort(vec, 0, vec.size() - 1);

    for (auto &item : vec)
        cout << item << ' ';
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, arr2;

//병합
void merge(int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;    //분할된 좌측 배열 첫번째 인덱스
    int j = mid + 1; //분할된 우측 배열 첫번째 인덱스
    int k = left;
    //좌측을 모두 탐색하고 && 우측을 모두 탐색할 때까지
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
            arr2[k++] = arr[j++];
    }

    int temp = i > mid ? j : i;

    while (k <= right)
    {
        arr2[k++] = arr[temp++];
    }

    for (int i = left; i <= right; i++)
        arr[i] = arr2[i];
}

//분할
void partition(int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid + 1, right);
        merge(left, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        arr2.push_back(0);
    }

    partition(0, arr.size() - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
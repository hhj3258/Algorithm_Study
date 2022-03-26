#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int data[], int start, int end)
{
    if (start >= end)
        return;

    int key = start;
    int left = start + 1;
    int right = end;

    while (left <= right)
    {
        while (left <= end && data[left] <= data[key])
        {
            left++;
        }

        while (right > start && data[right] >= data[key])
        {
            right--;
        }

        //엇갈렸다면 key와 right를 swap
        if (left > right)
        {
            swap(data[key], data[right]);
        }
        else
        {
            swap(data[left], data[right]);
        }
    }

    quickSort(data, start, right - 1);
    quickSort(data, right + 1, end);
}

int main()
{
    int data[] = {4, 5, 3, 2, 2, 10};
    quickSort(data, 0, 5);

    for (int i : data)
        cout << i << ' ';
}
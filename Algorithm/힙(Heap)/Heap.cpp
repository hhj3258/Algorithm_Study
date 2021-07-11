#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void Print_heap(vector<int> heap_arr);

vector<int> heap_arr;
int idx = 0;
int result;

// ÈüÀÇ »ğÀÔ ¸Ş¼Òµå
void Heap_push(int data, vector<int> &heap_arr)
{
    if (heap_arr.size() == 0)
        heap_arr.push_back(0);

    heap_arr.push_back(data);

    idx = heap_arr.size() - 1;

    while ((idx != 1) && (data > heap_arr[idx / 2]))
    {
        swap(heap_arr[idx], heap_arr[idx / 2]);

        idx = idx / 2;
    }

    result = heap_arr[1];
}

void Heap_pop(vector<int> &heap_arr)
{
    result = heap_arr[1];
    heap_arr[1] = heap_arr[heap_arr.size() - 1];
    heap_arr[heap_arr.size() - 1] = result;

    int parent = 1;
    int child;

    while (true)
    {
        child = parent * 2;

        if (child + 1 < heap_arr.size() - 1 && heap_arr[child] < heap_arr[child + 1])
            child++;

        if (child >= heap_arr.size() - 1 || heap_arr[child] < heap_arr[parent])
            break;

        swap(heap_arr[child], heap_arr[parent]);

        parent = child;
    }

    heap_arr.erase(heap_arr.end() - 1);

    result = heap_arr[1];
}

int Heap_top()
{
    if (heap_arr.size() == 0)
        return -1;
    return result;
}

void Print_heap(vector<int> heap_arr)
{
    cout << "heap: ";
    for (int i = 0; i < heap_arr.size(); i++)
    {
        cout << heap_arr[i] << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    vector<int> input_arr = {41, 67, 34, 0, 69, 78, 62, 64};

    for (int i = 0; i < input_arr.size(); i++)
    {
        Heap_push(input_arr[i], heap_arr);
    }
    cout << "top: " << Heap_top() << endl;
    Print_heap(heap_arr);

    Heap_pop(heap_arr);
    cout << "top: " << Heap_top() << endl;
    Print_heap(heap_arr);

    Heap_pop(heap_arr);
    cout << "top: " << Heap_top() << endl;
    Print_heap(heap_arr);
}

#include <iostream>
using namespace std;

int v1[1000000];
int v2[1000000];

void merge(int left, int right)
{
    int mid = (left + right) / 2;
    int L = left;
    int R = mid + 1;
    int K = left;

    while (L <= mid && R <= right)
    {
        if (v1[L] < v1[R])
            v2[K++] = v1[L++];
        else
            v2[K++] = v1[R++];
    }

    int min_idx;
    if (L <= mid)
        min_idx = L;
    else
        min_idx = R;

    while (K <= right)
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
    scanf("%d", &n);

    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        v1[i] = temp;
    }

    partition(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", v1[i]);
}
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, M;
int A[100001];
int B[100001];

int binarySearch(int key)
{
    int s_idx = 0;
    int e_idx = N - 1;

    while (s_idx <= e_idx)
    {
        int mid = (s_idx + e_idx) / 2;

        if (key == A[mid])
        {
            return 1;
        }
        if (key < A[mid])
        {
            e_idx = mid - 1;
        }
        else if (key > A[mid])
        {
            s_idx = mid + 1;
        }
    }

    return 0;
}

// void Solve(vector<int> A, vector<int> B)
// {
//     sort(A.begin(), A.end());

//     for (int i = 0; i < B.size(); i++)
//         printf("%d\n", binarySearch(A, B[i]));
// }

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    //Solve(A, B);

    sort(A, A + N);

    for (int i = 0; i < M; i++)
        printf("%d\n", binarySearch(B[i]));
}
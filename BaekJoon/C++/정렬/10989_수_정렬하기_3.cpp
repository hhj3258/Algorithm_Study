#include <stdio.h>

int main()
{
    int T, n;
    int count[10001] = {
        0,
    }; //숫자의 최대값만큼 할당

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        count[n]++;
    }

    for (int i = 0; i < 10001; i++)
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
                printf("%d\n", i);
}
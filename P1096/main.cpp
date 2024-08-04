#include <cstdio>

int step[100];

int main()
{
    int n, l = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            step[j] = 2 * step[j];
        }
        step[0] += 2;
        for (int i = 0; i < l; i++)
        {
            step[i + 1] += step[i] / 10;
            step[i] %= 10;
        }
        for (;;)
        {
            if (step[l] > 9)
            {
                step[l + 1] += step[l] / 10;
                step[l++] %= 10;
            }
            else break;
        }
    }
    for (int i = l; i >= 0; i--)
    {
        printf("%d", step[i]);
    }
    return 0;
}
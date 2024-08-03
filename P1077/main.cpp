#include <cstdio>

int a[101], b[101][101];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i <= n; i++) b[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = j; k >= j - a[i]; k--)
            {
                if (k >= 0)
                {
                    b[i][j] += b[i - 1][k] % 1000007;
                    b[i][j] %= 1000007;
                }
                else break;
            }
        }
    }
    printf("%d", b[n][m]);
    return 0;
}
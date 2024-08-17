#include <cstdio>

int h, n, ans, now;

int main()
{
    scanf("%d", &n);
    scanf("%d", &ans);
    now = ans;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &h);
        if (h > now) ans += (h - now);
        now = h;
    }
    printf("%d", ans);
    return 0;
}
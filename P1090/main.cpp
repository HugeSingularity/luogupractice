#include <cstdio>
#include <algorithm>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    int t = n - 1;
    int pile1[n], pile2[n];
    memset(pile2, 0, sizeof(pile2));
    for (int i = 0; i < n; i++)
        scanf("%d", pile1 + i);
    std::sort(pile1, pile1 + n);
    int i = 0, j = 0, cnt = -1, total = 0;

    while (t--)
    {
        int tmp = 0;
        if (i == n || pile1[i] > pile2[j] && j <= cnt)
        {
            tmp += pile2[j++];
        }
        else
        {
            tmp += pile1[i++];
        }

        if (i == n || pile1[i] > pile2[j] && j <= cnt)
        {
            tmp += pile2[j++];
        }
        else
        {
            tmp += pile1[i++];
        }
        pile2[++cnt] = tmp;
        total += tmp;
    }

    printf("%d", total);

    return 0;
}
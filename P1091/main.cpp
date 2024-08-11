#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int l[n], r[n], all[n], t[n];
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", t + i);
        r[i] = 1;
        l[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (t[i] > t[j] && r[i] <= r[j] + 1)
                {
                    r[i] = r[j] + 1;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (t[i] > t[j] && l[i] <= l[j] + 1)
                {
                    l[i] = l[j] + 1;
                }
            }
        }
        all[i] = l[i] + r[i] - 1;
    }
    sort(all, all + n);
    printf("%d", n - all[n - 1]);
    return 0;
}
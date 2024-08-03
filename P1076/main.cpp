#include <cstdio>

struct room
{
    bool stair;
    int number;
}rooms[10005][105];

int l[10005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        l[i] = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d%d", &rooms[i][j].stair, &rooms[i][j].number);
            if (rooms[i][j].stair) l[i]++;
        }
    }
    int start, ans = 0;
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
    {
        ans += rooms[i][start].number;
        ans %= 20123;
        int k = (rooms[i][start].number - 1) % l[i] + 1;
        for (int j = start;; j++)
        {
            if (j == m) j = 0;
            if (rooms[i][j].stair == 1) k--;
            if (!k)
            {
                start = j;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
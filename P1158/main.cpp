#include<cstdio>
#include<algorithm>

using namespace std;

int x1, y1, x2, y2, n, ans, d[100007];

struct node
{
    int x = 0;
    int y = 0;
}w[100007];

bool bigger(node a, node b)
{
    int q = (x1 - a.x) * (x1 - a.x) + (y1 - a.y) * (y1 - a.y);
    int p = (x1 - b.x) * (x1 - b.x) + (y1 - b.y) * (y1 - b.y);
    return(q < p);
}

int main() {
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i].x, &w[i].y);
    }
    sort(w, w + n, bigger);
    for (int i = n - 1; i >= 0; i--)
    {
        int h = (x2 - w[i].x) * (x2 - w[i].x) + (y2 - w[i].y) * (y2 - w[i].y);
        d[i] = max(d[i + 1], h);
    }
    ans = d[0];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        cnt = (x1 - w[i].x) * (x1 - w[i].x) + (y1 - w[i].y) * (y1 - w[i].y);
        cnt += d[i + 1];
        ans = min(ans, cnt);
    }
    ans = min(ans, d[0]);
    printf("%d", ans);
    return 0;
}
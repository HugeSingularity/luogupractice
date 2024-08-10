#include <cstdio>
#include <algorithm>

using namespace std;

int n, r, q;

struct competitor
{
    long long power, number, score;
    bool operator<(const competitor& t)
        const {
        if (t.score == score) return number < t.number;
        return score > t.score;
    }
}a[200000], loser[200000], winner[200000];

bool bigger(competitor x, competitor y)
{
    if (x.score == y.score) return x.number < y.number;
    return x.score > y.score;
}

void fighting()
{
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (a[i].power > a[i + 1].power)
        {
            a[i].score++;
            loser[i / 2] = a[i + 1];
            winner[i / 2] = a[i];
        }
        else
        {
            a[i + 1].score++;
            loser[i / 2] = a[i];
            winner[i / 2] = a[i + 1];
        }
    }
    return;
}

int main()
{
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 0; i < 2 * n; i++)
    {
        a[i].number = i + 1;
        scanf("%d", &a[i].score);
    }
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", &a[i].power);
    }
    sort(a, a + 2 * n);
    for (int i = 0; i < r; i++)
    {
        fighting();
        merge(loser, loser + n, winner, winner + n, a);
    }
    printf("%lld", a[q - 1].number);
    return 0;
}
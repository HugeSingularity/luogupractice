#include <cstdio>

struct Place
{
    int x = 0, y = 0;
};

Place soldier, horse, goal;
int ans;

void dfs()
{
    if (soldier.x == goal.x && soldier.y == goal.y)
    {
        ans++;
        return;
    }
    if ((soldier.x == horse.x + 1 && soldier.y == horse.y + 2) || (soldier.x == horse.x + 2 && soldier.y == horse.y + 1) || (soldier.x == horse.x + 2 && soldier.y == horse.y - 1) || (soldier.x == horse.x + 1 && soldier.y == horse.y - 2) || (soldier.x == horse.x - 1 && soldier.y == horse.y - 2) || (soldier.x == horse.x - 2 && soldier.y == horse.y - 1) || (soldier.x == horse.x - 2 && soldier.y == horse.y + 1) || (soldier.x == horse.x - 1 && soldier.y == horse.y + 2) || (soldier.x == horse.x && soldier.y == horse.y)) return;
    if (soldier.x + 1 <= goal.x)
    {
        soldier.x++;
        dfs();
        soldier.x--;
    }
    if (soldier.y + 1 <= goal.y)
    {
        soldier.y++;
        dfs();
        soldier.y--;
    }
    return;
}

int main()
{
    scanf("%d%d%d%d", &goal.y, &goal.x, &horse.y, &horse.x);
    dfs();
    printf("%d", ans);
    return 0;
}
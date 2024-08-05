#include <cstdio>

int horseX, horseY, goalX, goalY;
int hx[9] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
int hy[9] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
bool h[40][40];
long long chess[40][40];

int main()
{
    scanf("%d%d%d%d", &goalY, &goalX, &horseY, &horseX);
    goalX += 2, goalY += 2, horseX += 2, horseY += 2;
    for (int i = 0; i < 9; i++)
        h[horseY + hy[i]][horseX + hx[i]] = 1;
    for (int i = 2; i <= goalY; i++)
    {
        if (h[i][0]) break;
        chess[i][0] = 1;
    }
    for (int i = 2; i <= goalX; i++)
    {
        if (h[0][i]) break;
        chess[0][i] = 1;
    }
    for (int i = 2; i < goalY; i++)
    {
        for (int j = 2; j <= goalX; j++)
        {
            if (h[i][j]) continue;
            chess[i][j] += chess[i - 1][j] + chess[i][j - 1];
        }
    }
    printf("%d", chess[goalX][goalY]);
    return 0;
}
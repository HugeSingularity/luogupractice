#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int p, sav[1001], res[1001], f[1001];

void result_1()
{
    memset(sav, 0, sizeof(sav));
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            sav[i + j - 1] += res[i] * f[j];
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(res, sav, sizeof(res));
}

void result_2()
{
    memset(sav, 0, sizeof(sav));
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            sav[i + j - 1] += f[i] * f[j];
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(f, sav, sizeof(f));
}

int main()
{
    scanf("%d", &p);
    printf("%d", (int)(log10(2) * p + 1)); 
    res[1] = 1;
    f[1] = 2;
    while (p)
    {
        if (p % 2 == 0)
        {
            result_1();
        }
        p /= 2;
        result_2();
    }
    for (int i = 500; i > 0; i--)
    {
        if (i % 50 == 0) printf("\n%d", res[i]);
        else printf("%d", res[i]);
    }
    return 0;
}
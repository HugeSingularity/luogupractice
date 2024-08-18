#include<cstdio>

int n, m, k, x, a[1000005];

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &x);
    long long i; 
    a[0] = x;
    for (i = 1;; i++) 
    {
        x += m;
        if (x >= n) x -= n;
        a[i] = x;
        if (x == a[0]) break;
    }
    int l = k / 10, r = k % 10;
    int q = 1;
    for (int j = 0; j < l; j++) q = q * 10000000000 % i;
    for (int j = 0; j < r; j++) q = q * 10 % i;
    printf("%d", a[q]);
    return 0;
}
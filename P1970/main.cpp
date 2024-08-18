#include <cstdio>
#include <iostream>

using namespace std;

int n, h[100010], f[100010][2];

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (h[i] > h[i - 1]) f[i][0] = f[i - 1][1] + 1;
        else f[i][0] = f[i - 1][0];
        if (h[i] < h[i - 1]) f[i][1] = f[i - 1][0] + 1;
        else f[i][1] = f[i - 1][1];
    }
    printf("%d", max(f[n - 1][0], f[n - 1][1]));
    return 0;
}
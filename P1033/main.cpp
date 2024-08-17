#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double h, s1, v, l, k;

int main()
{
    scanf ("%lf%lf%lf%lf%lf%d", &h, &s1, &v, &l, &k, &n);
    double tMax = sqrt(h / 5);
    double tMin = sqrt((h - k) / 5);
    int i1 = int(s1 - tMin * v + l), i2 = int(s1 - tMax * v);
    i1 = min(i1, n);
    i2 = max(i2, 0);
    printf("%d", i1 - i2);
    return 0;
}

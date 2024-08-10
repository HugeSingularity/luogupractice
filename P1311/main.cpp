#include<cstdio>

using namespace std;

int n, k, p, t, ans, price, num[110], color[200100];

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &color[i], &price);
		if (price <= p)
		{
			for (int j = i; j > t; j--) num[color[j]]++;
			t = i, ans += num[color[i]] - 1;
		}
		else ans += num[color[i]];
	}
	printf("%d", ans);
	return 0;
}
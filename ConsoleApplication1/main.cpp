#include<iostream>
#include<cstdio>
using namespace std;
int g[105], f[105], a[105], s[105];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = 1;
		g[i] = 1;
	}//输入并赋初值 
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j] && f[i] <= f[j] + 1)
			{
				f[i] = f[j] + 1;
			}
		}
	}//从右往左，按左高右低顺序找出每一个位置右边有几个从高到低的数 （包括自己） 
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && g[i] <= g[j] + 1)
			{
				g[i] = g[j] + 1;
			}
		}
	}//从左往右，按左低右高顺序找出每一个位置左边有几个从低到高的数 （包括自己） 
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] = f[i] + g[i] - 1;//把每个数的左边从低到高的数和右边从高到低的数相加 
		//注意！！自己加了两次要-1 
		if (s[i] > maxx)
		{
			maxx = s[i];
		}
	}
	cout << n - maxx;//是求出列的人数 
}
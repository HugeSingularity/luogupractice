#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
struct word 
{
    string line;
    int left = 2;
}w[25];
int n, maxA;
inline int find(int last, int next)
{
    int lenl = w[last].line.length(), lenn = w[next].line.length();
    for (int i = lenl - 1; i >= 1; --i)
    {
        if (w[last].line[i] == w[next].line[0])
        {
            int k = i, j = 0, cl = 0;
            while (j < lenn && k < lenl)
            {
                if (w[last].line[k] == w[next].line[j])++cl;
                else return 0;
                ++k; ++j;
            }
            if (k == lenl && j < lenn)return cl;
            else return 0;
        }
    }
    return 0;
}
inline void dfs(int now, int length)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!w[i].left)continue;
        else
        {
            int x = find(now, i);
            if (x)
            {
                flag = true;
                --w[i].left;
                length += (w[i].line.length() - x);
                dfs(i, length);
                ++w[i].left;
                length -= (w[i].line.length() - x);
            }
            else flag = false;
        }
    }
    if (!flag) maxA = max(maxA, length);

}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)cin >> w[i].line;
    char p = getchar(); cin >> p;
    for (int i = 1; i <= n; i++)
    {
        if (w[i].line[0] == p)
        {
            --w[i].left;
            dfs(i, w[i].line.length());
            ++w[i].left;
        }
    }
    printf("%d", maxA);
    return 0;
}
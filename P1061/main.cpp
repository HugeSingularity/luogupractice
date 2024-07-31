#include <iostream>
using namespace std;

int s, t, w;

int main()
{
    string ans;
    cin >> s >> t >> w >> ans;
    for (int i = 0; i < 5; i++)
    {
        for (int j = w - 1; j; j--)
        {
            if (ans[j] - 'a' + 1 <= j - w + t)
            {
                ans[j]++;
                for (int k = j + 1; k < w; k++)
                    ans[k] = ans[k - 1] + 1;
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}
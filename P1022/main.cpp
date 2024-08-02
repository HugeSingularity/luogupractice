#include <iostream>
#include <iomanip>
using namespace std;

double k, b, now;
char tmp, x;
bool pm = true, a = true, last = false;

int main()
{
    while (cin >> tmp)
    {
        if (tmp == '+')
        {
            if (a == true)
            {
                pm = true;
            }
            else pm = false;
            last = false;
        }
        else if (tmp == '-')
        {
            if (a == true)
            {
                pm = false;
            }
            else pm = true;
            last = false;
        }
        else if (tmp == '=')
        {
            a = false;
            pm = false;
            last = false;
        }
        else if (tmp >= '0' && tmp <= '9')
        {
            if (last == true)
            {
                if (pm)
                {
                    now = now * 10 + (tmp - '0');
                }
                else now = now * 10 - (tmp - '0');
            }
            else
            {
                if (pm) now = tmp - '0';
                else now = -(tmp - '0');
                last = true;
            }
        }
        else
        {
            x = tmp;
            if (now == 0 && !last) now = 1;
            k += now;
            last = false;
            now = 0;
        }
        if (!last)
        {
            b += now;
            now = 0;
        }
    }
    b += now;
    double ans = -b / k;
    if (ans == -0.0) ans = 0;
    cout << fixed << setprecision(3);
    cout << x << "=" << ans;
    return 0;
}
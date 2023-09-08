#include <bits/stdc++.h>
using namespace std;
int n, a[200001], am[200001], duong[200001], tmax = - 1;
void load()
{
    cin >> n;
    am[0] = duong[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            am[i] = min(a[i], am[i-1]);
            if (a[i-1] != 0) tmax = max(tmax, abs(a[i] + am[i-1]));
        }
        else am[i] = am[i-1];
        if (a[i] > 0)
        {
            duong[i] = max(duong[i-1], a[i]);
            if (a[i-1] != 0) tmax = max(tmax, a[i] + duong[i - 1]);
        }
        else duong[i] = duong[i-1];
        if (a[i] == 0)
        {
            tmax = max(tmax, max(duong[i-1], abs(am[i-1])));
        }
    }
    cout << tmax;
}
int main()
{
    load();
    return 0;
}


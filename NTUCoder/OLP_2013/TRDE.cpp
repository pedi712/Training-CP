#include <bits/stdc++.h>
#define MAXN 100001
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 1e8;
void sol()
{
    ll k; cin >> k;
    bool ok = 0;
    int a, b;
    for(ll i = 2; i * i <= k; i++)
    {
        if ((2 * k - i - 1) % (2 * i + 1) == 0)
        {
            if(!ok)
            {
                ok = 1;
                a = i, b = b = (2 * k - i - 1) / (2 * i + 1);
            }
            else
            {
                if(abs(a - b) > abs(i - (2 * k - i - 1) / (2 * i + 1)))
                {
                    a = i, b = (2 * k - i - 1) / (2 * i + 1);
                }
            }
        }
    }
    if(!ok) cout << -1;
    else cout << min(a, b) << " " << max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}


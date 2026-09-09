#include <bits/stdc++.h>
#define MAXN 2000020
#define oo (1 << 31) - 1
#define base 311
#define plli pair<long long, int>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;
const ll M = 1ll * MOD * MOD;
int n;
ll hashh[MAXN];
ll revhash[MAXN];
ll h[MAXN];
ll gethash(int l, int r)
{
    return (hashh[r] - hashh[l - 1] * h[r - l + 1] + M) % MOD;
}
ll getrevhash(int l, int r)
{
    return (revhash[l] - revhash[r + 1] * h[r - l + 1] + M) % MOD;
}
void sol()
{
    string s;
    cin >> n >> s;s = '@' + s + '@';
    hashh[0] = 0;
    h[0] = 1;
    for(int i = 1; i <= 2 * n; i++)
    {
        hashh[i] = (hashh[i - 1] * base + s[i]) % MOD;
        h[i] = (h[i - 1] * base) % MOD;
    }
    revhash[2 * n + 1] = 0;
    for(int i = 2 * n; i > 0; i--)
    {
        revhash[i] = (revhash[i + 1] * base + s[i]) % MOD;
    }
    bool f = 0;
    for(int i = 1; i <= n; i++)
    {
        if(hashh[i] == getrevhash(n + 1, n + i) && gethash(n + i + 1, 2 * n) == getrevhash(i + 1, n))
        {
            f = 1;
            for(int j = 1; j <= i; j++) cout << s[j];
            for(int j = 2 * n - (n - i - 1); j <= 2 * n; j++) cout << s[j];
            cout << "\n";
            cout << i << '\n';
            break;
        }
    }
    if(!f) cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
    return 0;
}

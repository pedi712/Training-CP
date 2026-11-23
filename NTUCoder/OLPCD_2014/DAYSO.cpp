#include <bits/stdc++.h>
#define MAXN 1300
#define pii pair<int, int>
#define w first
#define v second
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const int MOD = (int)1e6;
map<int, bool> s;
int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
void sol()
{
    int n; cin >> n;
    int a[MAXN];
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll mi[3] = {0};
    mi[0] = a[1] + a[2] + a[3];
    mi[1] = a[1];
    mi[2] = a[2] + a[1];
    ll sum = a[1] + a[2] + a[3];
    ll mx = mi[0];
    for(int i = 4; i <= n; i++)
    {
        sum += a[i];
        if(i % 3 == 0) mx = max(mx, sum);
        mx = max(mx, sum - mi[i % 3]);
        mi[i % 3] = min(mi[i % 3], sum);
        //cout << mx << " ";
    }
    cout << mx;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}


#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7, N = 2e5;
int a[N];
bool ok[N];
vector<vector<int>> g;
void dfs(int u)
{
    ok[u] = 1;
    for(auto v: g[u])
    {
        if(!ok[v])
        {
            dfs(v);    
        }
    }
}
void sol()
{
    int t; cin >> t;
    while(t--)
    {
        g.clear();
        int n, m; cin >> n >> m;
        g.resize(n + 10, vector<int>());
        int u, lu, v, lv;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) 
        {
            cin >> u >> lu >> v >> lv;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) ok[i] = 0;
        dfs(1);
        string re = "YES";
        for(int i = 1; i <= n; i++) if(!ok[i]) re = "NO";
        cout << re << "\n";
    }
}
signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}

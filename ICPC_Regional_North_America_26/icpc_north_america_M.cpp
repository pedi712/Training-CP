#include <bits/stdc++.h>
#define pii pair<pair<int,int>, int>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fi first
#define int long long
#define oo 10000000000000
#define se second
using namespace std;
const int N = 12;
// gọi dp[i][j] la so tien nho nhat nguoi i can de thang o cap i
void sol()
{
    int k; cin >> k;
    bool val[(1 << N)][(1 << N)] = {0};
    int b[(1 << N)] = {0};
    string s;
    for(int i = 1; i <= (1 << k); i++)
    {
        cin >> b[i];
        cin >> s;
        for(int j = 0; j < (int)s.size(); j++)
        {
            val[i][j + 1] = s[j] - '0';
            //cout << i << " " << j + 1 << " " <<  val[i][j + 1] << "\n";
        }
    }
    int dp[(1 << N)][N] = {0};
    for(int i = 1; i <= (1 << k); i++) for(int j = 1; j <= k; j++) dp[i][j] = oo;
    for(int lv = 1; lv <= k; lv++)
    {
        int st = 1;
        while(st <= (1 << k))
        {
            for(int i = st; i < st + (1 << lv); i++)
            {
                for(int j = st; j < (st + (1 << lv)); j++)
                {
                    if(i != j)
                    {
                        dp[i][lv] = min(dp[i][lv], dp[i][lv - 1] + dp[j][lv - 1] + !val[i][j] * b[j]);
                    }
                }
            }
            st += (1 << lv);
        }
    }
    cout << dp[1][k] << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) sol();
}

#include <bits/stdc++.h>
#define pii pair<int, int>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fi first
#define se second
using namespace std;

void sol()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        int k;
        cin >> n >> k;
        int cnt2 = 0;
        while(n % (1 << (cnt2 + 1)) == 0)
        {
            cnt2++;
        }   
        map<int, bool> s;
        int cnt = 0;
        vector<pii> st;
        st.push_back({n, 0});
        while(!st.empty())
        {
            pii tmp = st.back();
            st.pop_back();
            if(tmp.se < k)
            {
                st.push_back({tmp.fi / 2, tmp.se + 1});
                if((tmp.fi) % 2 != 0) st.push_back({tmp.fi / 2 + 1, tmp.se + 1});
            }
            else 
            {
                if(!s[tmp.fi]) cnt++;
                s[tmp.fi] = 1;
            }
        }
        cout << cnt << '\n';
    }
}
signed main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}

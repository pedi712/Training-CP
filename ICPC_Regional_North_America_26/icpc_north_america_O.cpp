#include <bits/stdc++.h>
#define pii pair<pair<int,int>, int>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fi first
#define se second
using namespace std;
const int N = 1000;
void sol()
{
    int t; cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        bool nq = 1, tl = 1;
        int to[N];
        int cua[N];
        for(int i = 0; i < N; i++) to[i] = -1, cua[i] = -1;
        for(int i = 0; i < (int)s.size(); i++)
        {
            s[i] -= 'a';
            t[i] -= 'a';
            if(to[s[i]] == -1)
            {
                to[s[i]] = t[i];
            }
            else
            {
                if(to[s[i]] != t[i]) nq = 0;
            }
        }
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(cua[t[i]] == -1)
            {
                cua[t[i]] = s[i];
            }
            else 
            {
                if(cua[t[i]] != s[i]) tl = 0;
            }
        }
        cout << (nq && tl ? "YES" : "NO") << "\n";
    }
}
signed main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}

#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int t; cin >> t;
    string opt;
    int val;
    while(t--)
    {
        int d, q; cin >> d >> q;
        while(q--)
        {
            cin >> opt >> val;
            int p = 0;
            while(val > 1)
            {
                p++;
                val /= 10;
            }
            if(opt == "BANGA") d += 10 * p;
            else d -= 10 * p;
            cout << d << "\n"; 
        }
    }
}
signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}

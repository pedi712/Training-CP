#include <bits/stdc++.h>
#define MAXN 500001
#define oo 1000000000
#define plli pair<long long, int>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, q;
struct node
{
    char l, r;
    int cntl = 1, cntr = 1, mx = 1, len = 0;
};
node st[4 * MAXN];
string s;
node up(int l, int mid, int r, int id)
{
    node tmp;
    tmp.len = r - l + 1;
    tmp.l = st[id * 2].l;
    tmp.r = st[id * 2 + 1].r;
    tmp.cntl = st[id * 2].cntl;
    tmp.cntr = st[id * 2 + 1].cntr;
    if(st[id * 2].cntl == mid - l + 1 && st[id * 2].r == st[id * 2 + 1].l)
    {
        tmp.cntl = st[id * 2].cntl + st[id * 2 + 1].cntl;
    }
    if(st[id * 2 + 1].cntr == r - mid && st[id * 2 + 1].l == st[id * 2].r)
    {
        tmp.cntr = st[id * 2 + 1].cntr + st[id * 2].cntr;
    }
    tmp.mx = max(max(max(st[id * 2].mx, st[id * 2 + 1].mx), tmp.cntr), tmp.cntl);
    if(st[id * 2].r == st[id * 2 + 1].l) tmp.mx = max(tmp.mx, st[id * 2].cntr + st[id * 2 + 1].cntl);
    return tmp;
}
void build(int l, int r, int id)
{
    if(l == r)
    {
        st[id].l = s[l];
        st[id].r = s[l];
        st[id].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id * 2);
    build(mid + 1, r, id * 2 + 1);
    st[id] = up(l, mid, r, id);
}
void update(int l, int r, int id, int u, char c)
{
    if(l > u || r < u) return;
    if(l == r && r == u)
    {
        st[id].l = c;
        st[id].r = c;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id * 2, u, c);
    update(mid + 1, r, id * 2 + 1, u, c);
    st[id] = up(l, mid, r, id);
}
node get(int l, int r, int id, int u, int v)
{
    if(l > v || r < u)
    {
        node x;
        x.l = 'A';
        x.r = 'A';
        x.cntl = 0;
        x.cntr = 0;
        x.mx = 0;
        x.len = 0;
        return x;
    }
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    node le = get(l, mid, id * 2, u, v);
    node ri = get(mid + 1, r, id * 2 + 1, u, v);
    node re;
    re.l = le.l;
    re.r = ri.r;
    re.cntl = le.cntl;
    re.cntr = ri.cntr;
    if(le.cntl == le.len && le.r == ri.l)
    {
        re.cntl = le.cntl +  ri.cntl;
    }
    if(ri.cntr == ri.len && ri.l == le.r)
    {
        re.cntr = ri.cntr + le.cntr;
    }
    re.mx = max(max(max(le.mx, ri.mx), re.cntr), re.cntl);
    re.len = le.len + ri.len;
    if(le.r == ri.l) re.mx = max(re.mx, le.cntr + ri.cntl);
    return re;
}
void sol()
{
    cin >> n >> q;
    cin >> s;
    build(0, n - 1, 1);
    int type, i, l, r;
    char c;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> i >> c;
            update(0, n - 1, 1, i - 1, c);
        }
        else
        {
            cin >> l >> r;
            node res = get(0, n - 1, 1, l - 1, r - 1);
            cout << res.mx << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
    return 0;
}

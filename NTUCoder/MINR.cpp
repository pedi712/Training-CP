#include <iostream>
using namespace std;
int a[100001];
int seg[400010];
const int mins = 1e9+999;
void createsegtree(int l,int r,int idx){
  if (l == r){
    seg[idx] = a[l];
  }
  else{
    int mid = (l+r)/2;
    createsegtree(l,mid,idx*2);
    createsegtree(mid+1,r,idx*2+1);
    seg[idx] = min(seg[idx*2],seg[idx*2+1]);
  }
}
int get(int l,int r,int idx,int d,int t){
  if (t < l||d>r){
    return mins;
  }
  if (l >= d&& r <= t){
      return seg[idx];
  }
  if (t>=l||d<=r){
    int mid = (l+r)/2;
    int s = min(get(l,mid,idx*2,d,t),get(mid+1,r,idx*2+1,d,t));
    return s;
  }
}
int main(){
  int n,m;cin >> n >> m;
  for (int i = 0;i<n;i++){
    cin >> a[i];
  }
  createsegtree(0,n-1,1);
  for (int i = 0;i<m;i++){
    int t,d;
    cin >> d >> t;
    t-=1;
    d-=1;
    int e = get(0,n-1,1,d,t);
    cout << e << endl;
  }
}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int>a;
  for (int i = 0;i<n;i++){
    int b;
    cin >> b;
    a.push_back(b);
  }
  sort(a.begin(),a.end(),greater<int>());
  for (int i = 1;i<n;i++){
    a[i] = a[i-1]+a[i];
  }
  if (k == 1){
    cout << 0;
  }
  else{
    int res = 0;
    for (int i = 0;i<n;i++){
      res = i;
      if (a[i]-i >= k){
        break;
      }
    }
    if (a[n-1]-res< k){
      cout << -1;
    }
    else{
    cout << res+1;}
  }
}

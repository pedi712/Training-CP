#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int>a;
  vector<int>b;
  for (int i = 0;i<n;i++){
    int k;
    cin >> k;
    a.push_back(k);
  }
  for (int i = 0;i<n;i++){
    int k;
    cin >> k;
    b.push_back(k);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int i = 0;int j = 0;
  int res = 0;
  while (i < n&&j<n){
    if (a[i] < b[j]){
      i++;
      j++;
      res++;
    }
    else{
      j++;
    }
  }
  cout << res;
}

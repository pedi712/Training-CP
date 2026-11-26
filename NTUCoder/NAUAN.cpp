#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(){
  int n,m;
  map<int,int>maps;
  cin >> n;
  vector<int>a;
  for (int i = 0;i<n;i++){
    int k;
    cin >> k;
    a.push_back(k);
  }
  cin >> m;
  vector<int>p;
  for (int i = 0;i<m;i++){
    int k;
    cin >> k;
    p.push_back(k);
  }
  for (int i = 1;i<n;i++){
    a[i] = a[i-1]+a[i];
  }
  vector<int>s;
  for (int i = 0;i<m;i++){
    s.push_back(p[i]);
  }
  sort(s.begin(),s.end());
  int i = 0;int j=0;
  while (i <n&&j <m){
    if (s[j] > a[i]){
      i++;
    }
    else{
      maps[s[j]] = i+1;
      j++;
    }
  }
  for (int j = 0;j<m;j++){
    if (p[j] <= a[n-1]){
      cout << maps[p[j]] << " ";
    }
  }
}


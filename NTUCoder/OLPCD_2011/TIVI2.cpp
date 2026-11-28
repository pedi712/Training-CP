#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(vector<int>a,vector<int>b){
  if (a[0] < b[0]){
    return true;
  }
  return false;
}
int main(){
  int n;cin >> n;
  vector<vector<int> >a;
  for (int i = 0;i<n;i++){
    int x,y;
    cin >> x >> y;
    vector<int> b;
    b.push_back(x);
    b.push_back(y);
    a.push_back(b);
  }
  int cuoi[100001];
  for (int i = 0;i<n;i++){
    cuoi[a[i][1]]++;
  }
  int cuoi1[100001];
  for (int i = 1;i<=100000;i++){
    cuoi1[i] = cuoi1[i-1]+cuoi[i];
  }
  sort(a.begin(),a.end(),cmp);
  long long res = 0;
  for (int i = 0;i<n;i++){
    res += cuoi1[a[i][1]-1]-cuoi1[a[i][0]];
  }
  for (int i = 0;i<n;i++){
    int x =  cuoi[a[i][1]];
    long long l = ((x-1)*x)/2;
    res += l;
    cuoi[a[i][1]] = 0;
  }
  cout << res << endl;
}

#include <iostream>
#include <map>
using namespace std;
int main(){
  int n;
  cin >> n;
  map<long long,int>a;
  for (int i = 0;i<n;i++){
    long long s;
    cin >> s;
    a[s]++;
  }
  long long res = 0;
  for (pair<long long,int> it:a){
    if (it.second <= 5){
      res+=100;
    }
    else{
      res+=100+(it.second-5);
    }
  }
  cout << res;
}

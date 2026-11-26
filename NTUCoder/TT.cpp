#include <iostream>
#include <vector>
using namespace std;
vector<int>b;
int n;
int a[20];
int sums = 0;
int flag = 0;
int cc = 0;
vector<vector<int> > c;
void backtrack(int lens){
  if (lens == 0){
    int sums1 = 0;
    for (int i = 0;i<n;i++){
      if (b[i] == 0){
        sums1 += a[i];
      }
    }
    if (sums1 == sums-sums1){
      flag=1;
      cc++;
      c.push_back(b);
    }
  }
  else{
    for (int i = 0;i<2;i++){
      b.push_back(i);
      backtrack(lens-1);
      b.pop_back();
    }
  }
}
int main(){
  cin >> n;
  for (int i = 0;i<n;i++){
    cin >> a[i];
  }
  for (int i = 0;i<n;i++){
    sums += a[i];
  }
  backtrack(n);
  if (flag == 0){
    cout << "khong chia duoc";
  }
  else{
    cout << cc <<endl;
    for (int i = 0;i<cc;i++){
      for (int j = 0;j<n;j++){
        if (c[i][j] == 0){
          cout << 'A' << " ";
        }else{
          cout << 'B'<<" ";
        }
      }cout << endl;
    }
  }
}


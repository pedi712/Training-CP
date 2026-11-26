#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  int a[101][101];
  for (int i = 0;i<n;i++){
    for (int j = 0;j<m;j++){
      cin >> a[i][j];
    }
  }
  int b[101][101];
  b[0][0] = a[0][0];
  for (int i = 0;i<n;i++){
    for (int j = 0;j<m;j++){
      if (i == 0 && j == 0){
        continue;
      }
      else{
        if (i == 0){
          b[i][j] = b[i][j-1]+a[i][j];
        }
        if (j == 0){
          b[i][j] = b[i-1][j]+a[i][j];
        }
        else{
          b[i][j] = max(b[i-1][j],b[i][j-1])+a[i][j];
        }
      }
    }
  }
  cout << b[n-1][m-1];
}

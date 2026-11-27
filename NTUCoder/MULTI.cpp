#include <iostream>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int a[100010];
  for (int i = 0;i<n;i++){
    cin >> a[i];
  }
  int am[100010] = {0};
  am[0] = (a[0]<0)?1:0;
  int khong[100010] = {0};
  khong[0] = (a[0] == 0)?1:0;
  for (int i = 1;i<n;i++){
    int x = (a[i]>0)?1:0;
    int b = (a[i]<0)?1:0;
    int c = 1-(x+b);
    am[i] = am[i-1]+b;
    khong[i] = khong[i-1]+c;
  }
  for (int i = 0;i<m;i++){
    int l,r;
    cin >> l >> r;
    r-=1;
    l-= 1;
    int x = (a[l]>0)?1:0;
    int b = (a[l]<0)?1:0;
    int c = 1-(x+b);
    if (khong[r]-khong[l]+c > 0){
      cout << "0" << endl;
    }
    else{
      if ((am[r]-am[l]+b)%2 != 0){
        cout << "-" << endl;
      }
      else{
        cout << "+" << endl;
      }
    }
  }
}


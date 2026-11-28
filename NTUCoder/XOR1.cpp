#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;cin >> n;
    int chan = 0;long long res = 0;
    for (int i = 0;i<n;i++){
      int s;cin>>s;
      if (s%2 == 0){
        chan++;
        res += (i+1-chan);
      }
      else{
        res+=chan;
      }
    }
    cout << res;
}

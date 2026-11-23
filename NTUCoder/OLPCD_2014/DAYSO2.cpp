#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;cin >> n;
    int a[100010];
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    long long res[100010] = {0};
    res[0] = -1e18;
    res[1] = -1e18;
    res[2] = a[0]+a[1]+a[2];
    long long maxs = -1e18;
    for (int i = 3;i<n;i++){
        res[i] = a[i]+a[i-1]+a[i-2];
        if (i>=5){
            res[i] = max(res[i],res[i]+res[i-3]);
        }
    }
    for (int i = 0;i<n;i++){
        maxs = max(maxs,res[i]);
    }
    cout << maxs;
}

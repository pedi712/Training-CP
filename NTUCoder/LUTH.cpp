#include <iostream>
using namespace std;
const int mod = 1e4;
int nhanando(long long n,int x){
    if (n == 0){
        return 1%mod;
    }
    else{
        if (n%2 == 0){
            int a = (nhanando(n/2,x))%mod;
            return (a*a)%mod;
        }
        else{
            int a = (nhanando(n/2,x))%mod;
            return (x*(a*a)%mod)%mod;
        }
    }
}
int main(){
    int x;
    long long n;
    cin >> x >> n;
    int m = (nhanando(n,x))%mod;
    cout << m;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
int qpow(int x, int y, int q) {
    LL ans = 1;
    while (y) {
        if (y&1) ans = ans * x % q;
        y >>= 1;
        x = (LL)x * x % q;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    LL ans=1;
    for (int i=n+1;i<=2*n;++i) ans = ans * i % mod;
    for (int i=1;i<=n;++i) ans = ans * qpow(i, mod - 2, mod) % mod;
    ans = ans * qpow(n+1, mod - 2, mod) % mod;
    cout<<ans<<endl;
    return 0;
}

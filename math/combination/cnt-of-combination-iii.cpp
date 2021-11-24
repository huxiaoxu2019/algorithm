#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int fact[N],infact[N];
// lucas 卢卡斯定理 
// C(a,b) = C(a%q,b%q) * C(a/q,b/q), 在模 q 的情况下
// 证明略
int qpow(int a, int b, int q) {
    int ans=1;
    while (b) {
        if (b&1) {
            ans=(LL)ans*a%q;
        }
        a=(LL)a*a%q;
        b>>=1;
        
    }
    return ans;
}
int C(int a, int b, int q) {
    int ans = 1;
    for (int i=1,j=a;i<=b;++i,--j) {
        ans = (LL) ans * j % q;
        ans = (LL) ans * qpow(i, q-2, q) % q;
    }
    return ans;
}
int lucas(LL a, LL b, int q) {
    if (a < q && b < q) return C(a, b, q);
    return (LL)C(a%q,b%q,q)*lucas(a/q,b/q,q)%q;
}
int main () {
    LL n,a,b,q;
    cin>>n;
    while (n--) {
        cin>>a>>b>>q;
        int ans = lucas(a,b,q);
        cout<<ans<<endl;
    }
    return 0;
}

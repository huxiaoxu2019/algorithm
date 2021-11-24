#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int fact[N],infact[N];
int n,a,b,mod=1e9+7;
// C(a,b) = fact[a] * infact[b] * infact[a-b]
// a^b%q
int qpow(int a, int b, int q) {
    LL ans=1;
    while (b) {
        if (b&1) {
            ans=ans*a%q;
        }
        b>>=1;
        a=(LL)a*a%q;
    }
    return ans;
}

int main() {
    fact[0]=infact[0]=1;
    for (int i=1;i<N;++i) {
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i]=(LL)infact[i-1]*qpow(i,mod-2,mod)%mod;
        //cout<<fact[i]<<" "<<infact[i]<<endl;
    }
    //cout<<fact[3]<<" "<<infact[1]<<endl;
    cin>>n;
    while (n--) {
        cin>>a>>b;
        int ans=((LL)fact[a] * infact[b] % mod) * infact[a-b] % mod;
        cout<<ans<<endl;
    }
    return 0;
}

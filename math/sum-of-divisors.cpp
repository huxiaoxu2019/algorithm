#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n, a;
typedef long long LL;
LL sum=1;
unordered_map<int, int> primes;
int main() {
    cin>>n;
    while(n--) {
        cin>>a;
        for (int i=2;i<=a/i;++i) {
            while (a%i==0) {
                primes[i]++;
                a/=i;
            }
        }
        if (a>1) primes[a]++;
    }
    for (auto& x:primes) {
        int p=x.first, cnt=x.second;
        LL csum=1;
        // sum = (p^0 + p^1 + ... + p^k)
        // sum = p*sum+1
        while (cnt--) {
            csum = (p*csum+1)%MOD;
        }
        sum=(sum*csum)%MOD;
    }
    cout<<sum<<endl;
    return 0;
}

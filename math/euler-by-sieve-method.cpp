#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int prime[N], cnt, phi[N];
bool st[N];
typedef long long LL;
LL get_euler(int n) {
    phi[1] = 1;
    for (int i=2;i<=n;++i) {
        if (!st[i]) {
            prime[++cnt]=i;
            phi[i] = i - 1;
        }
        for (int j=1;prime[j]<=n/i&&j<=cnt;++j) {
            st[prime[j]*i]=true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] *  (prime[j] - 1);
        }
    }
    LL res = 0;
    for (int i=1;i<=n;++i) {
        res += phi[i];
        
    }
    return res;

}
int main() {
    int n;
    cin>>n;
    cout<<get_euler(n)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int mod = 1e9 + 7;
int n;
int f[N];
// f[i][j] = f[i-1][j] + f[i][j-i]
int main() {
    cin>>n;
    f[0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            f[j] = f[j] + f[j-i];
            f[j] %= mod;
        }
    }
    cout<<f[n]<<endl;
    return 0;
}

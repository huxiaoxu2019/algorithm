#include<bits/stdc++.h>
using namespace std;
const int N=510;
int g[N][N], n, f[N][N];
int main() {
    cin>>n;
    memset(f, -0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            cin>>g[i][j];
        }
    }
    f[1][1] = g[1][1];
    int ans=INT_MIN;
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=i;++j) {
            f[i][j]=g[i][j]+max(f[i-1][j], f[i-1][j-1]);
            if (i==n) ans=max(ans, f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

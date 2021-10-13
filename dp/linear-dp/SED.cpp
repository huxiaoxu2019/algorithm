#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char a[N],b[N];
int f[N][N],n,m;
int main() {
    cin>>n;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = i;
    }
    for (int i=1;i<=n;++i) cin>>a[i];
    cin>>m;
    for (int i = 1; i <= m; ++i) {
        f[0][i] = i;
    }
    for (int j=1;j<=m;++j) cin>>b[j];
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            f[i][j]=min(f[i-1][j]+1, min(f[i][j-1]+1,  f[i-1][j-1]+1));
            if (a[i]==b[j]) f[i][j]=min(f[i][j], f[i-1][j-1]);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}

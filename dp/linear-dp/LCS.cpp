#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char a[N],b[N];
int n,m,f[N][N];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int j=1;j<=m;++j) cin>>b[j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j) {
            f[i][j] = max(f[i][j-1], f[i-1][j]);
            if (a[i]==b[j]) f[i][j]=max(f[i][j], f[i-1][j-1]+1);
        }
    cout<<f[n][m]<<endl;
    return 0;
}

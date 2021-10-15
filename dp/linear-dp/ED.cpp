#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10, M=1e1+10;
int n,m,f[M][M],limit,ans;
char a[N][M],b[M];
int helper(int ai) {
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    // If modify f[M][0], it will change the value of var limit, which is after by f[M][M] in declaretion
    for (int i = 1; i < M; ++i) {
        f[i][0] = i;
        f[0][i] = i;
    }
    int len=strlen(a[ai]+1), len2=strlen(b+1);
    for (int i=1;i<=len;++i) {
        for (int j=1;j<=len2;++j) {
            f[i][j] = min(f[i-1][j]+1, min(f[i][j-1]+1, f[i-1][j-1]+1));
            if (a[ai][i]==b[j]) f[i][j]=min(f[i][j], f[i-1][j-1]);
        }
    }
    return f[len][len2];
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>(a[i]+1);
    }
    for (int i=1;i<=m;++i) {
        ans = 0;
        cin>>(b+1);
        cin>>limit;
        for (int j=1;j<=n;++j) {
            if (helper(j) <= limit) ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}

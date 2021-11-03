#include<bits/stdc++.h>
using namespace std;
const int N=310;
int f[N][N], s[N], a[N];
int n;
int main() {
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i] = s[i-1]+a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int l=1;l<=n;++l) {
        for (int i=1;i+l-1<=n;++i) {
            int j=i+l-1;
            if (i==j) f[i][j] = 0;
            for (int k=i;k<j;++k) {
                f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}

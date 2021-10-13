#include<bits/stdc++.h>
using namespace std;
const int N=110;
int f[N],s[N],v[N][N],w[N][N],n,V;
int main() {
    cin>>n>>V;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        for (int j=1;j<=s[i];++j) {
            cin>>v[i][j]>>w[i][j];
        }
    }

    for (int i=1;i<=n;++i) {
        for (int j=V;j>=0;--j) {
            for (int k=1;k<=s[i];++k) {
                if (j>=v[i][k]) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }
    cout<<f[V]<<endl;
    return 0;
}

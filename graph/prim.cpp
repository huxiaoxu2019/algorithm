#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
int d[N],g[N][N],vis[N];
void prim() {
    d[1]=0;
    for (int i=1;i<=n;++i) {
        int t=0;
        for (int j=1;j<=n;++j) {
            if (!vis[j] && (t==0||(d[j]<d[t]))) {
                t=j;
            }
        }
        vis[t]=1;
        for (int j=1;j<=n;++j) {
            if (!vis[j]) d[j]=min(d[j],g[t][j]);
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (d[i] > 0x3f3f3f3f / 2) {
            cout<<"impossible"<<endl;
            return;
        } else {
            ans+=d[i];
        }
    }
    cout<<ans<<endl;
}
int main() {
    memset(d, 0x3f, sizeof d);
    memset(g, 0x3f, sizeof g);
    for (int i=1;i<=n;++i) g[i][i]=0;
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        g[b][a]=g[a][b]=min(g[a][b], c);
    }
    prim();
    return 0;
}

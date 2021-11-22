// TC: O(n^3)
// https://www.cnblogs.com/Ash-ly/p/5920953.html
#include<bits/stdc++.h>
using namespace std;
const int N=210,M=1e5+10,INF=1e9;
int g[N][N],n,m,q,k;
void floyd() {
    // g[k][i][j] = min{g[k-1][i][k], g[k-1][k][j]}
    // 经过需要 1-k 个点的情况下，从 i 到 j 的最短距离
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i==j) g[i][j]=0;
            else g[i][j]=INF;
        }
    }
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    floyd();
    for (int i=0;i<k;++i) {
        int a,b;
        cin>>a>>b;
        if (g[a][b] > INF / 2) cout<<"impossible"<<endl;
        else cout<<g[a][b]<<endl;
    }
    return 0;
}

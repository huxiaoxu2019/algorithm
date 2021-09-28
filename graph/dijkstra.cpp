#include<bits/stdc++.h>
using namespace std;
const int N=505;
int d[N],v[N],n,m,g[N][N];
void dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1]=0;
    for (int i=0;i<n;++i) {
        int t=-1;
        for (int j=1;j<=n;++j) {
            if (!v[j]&&(t==-1||d[t]>d[j])) {
                t=j;
            }
        }
        v[t]=1;
        for (int j=1;j<=n;++j) {
            d[j] = min(d[j], d[t] + g[t][j]);
        }
    }
    if (d[n] >= 0x3f3f3f3f) {
        cout<<-1<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}
int main() {
    cin>>n>>m;
    memset(g, 0x3f, sizeof g);
    for(int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    dijkstra();
    return 0;
}

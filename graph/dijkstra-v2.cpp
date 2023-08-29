#include<bits/stdc++.h>
using namespace std;
const int N=510, M=1e5+10;

int d[N], v[N], n, m, g[N][N];

void dijkstra() {
    memset(d, 0x3f, sizeof d);
    memset(v, 0, sizeof v);
    d[1]=0;
    for (int i=2;i<=n;++i) {
        // loop for n-1 times
        int t=-1;
        for (int j=1;j<=n;++j) {
            if (!v[j] && (t == -1 | d[j] < d[t])) t = j;
        }
        v[t]=1;
        for (int j=1;j<=n;++j) {
            d[j] = min(d[j], d[t] + g[t][j]);
        }
    }

    if (d[n] == 0x3f3f3f3f) {
        cout<<-1<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}

int main() {
    cin>>n>>m;
    memset(g, 0x3f, sizeof g);
    for (int i=0;i<m;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u][v]=min(w, g[u][v]);
    }
    dijkstra();
    return 0;
}


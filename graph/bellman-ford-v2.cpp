#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N=510, M=1e4+5;
struct Edge {
    int u, v, w;
} edges[M];
int d[N], bd[N];
void bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i=0;i<k;++i) {
        memcpy(bd, d, sizeof d);
        for (int j=1;j<=m;++j) {
            int a = edges[j].u, b = edges[j].v, c = edges[j].w;
            d[b] = min(d[b], bd[a] + c);
        }
    }
    if (d[n] > 0x3f3f3f3f / 2) {
        cout<<"impossible"<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i) {
        int a, b, c;
        cin>>a>>b>>c;
        edges[i].u=a, edges[i].v=b, edges[i].w=c;
    }
    bellman_ford();
    return 0;
}


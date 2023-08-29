#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
// 邻接表
int ver[N], edge[N], Next[N], head[N], tot;
int d[N], v[N];
int n,m;
void add(int u, int v, int w) {
    ver[++tot] = v;
    edge[tot] = w;
    Next[tot] = head[u];
    head[u] = tot;
    /**
    for (int i=head[u]; i; i = Next[i]) {
        auto u = ver[i]...
    }
    **/
}

priority_queue<pair<int, int>> pq; // first: -dist, second: u

void dijstra() {
    memset(d, 0x3f, sizeof d);
    d[1]=0;
    pq.push({0, 1});
    while (pq.size()) {
        auto u = pq.top().second; pq.pop();
        if (v[u]) continue;
        v[u]=1;
        for (int i=head[u];i;i=Next[i]) {
            auto v=ver[i], w=edge[i];
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
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
    for (int i=0;i<m;++i) {
        int u, v, w;
        cin>>u>>v>>w;
        add(u, v, w);
    }
    dijstra();
    return 0;
}

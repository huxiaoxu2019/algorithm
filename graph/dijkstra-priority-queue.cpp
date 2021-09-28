#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10+5e4;
int head[N],Next[N],tot,ver[N],edg[N];
int n,m,d[N],vis[N];
// first is distance, second is no. big-root heap for default.
priority_queue<pair<int, int>> pq;
void add(int a, int b, int c) {
    ver[++tot]=b;
    edg[tot]=c;
    Next[tot]=head[a];
    head[a]=tot;
}

void dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1]=0;
    pq.push({0,1});
    while (!pq.empty()) {
        auto pa=pq.top(); pq.pop();
        auto u=pa.second;
        if (vis[u]) continue;
        // vis for de-duplication, variable name is best to use vis not v.
        vis[u]=1;
        for (int i=head[u];i!=-1;i=Next[i]) {
            auto v=ver[i], w=edg[i];
            if (d[v] > d[u]+w) {
                d[v]=d[u]+w;
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
    // remember for where to set the head var!!!
    memset(head, -1, sizeof head);
    cin>>n>>m;
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dijkstra();
    return 0;
}

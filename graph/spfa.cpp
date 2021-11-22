// TIP: add the point to queue, which will decrease the dist from starting point
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],q[N],head[N],ver[N],edge[N],Next[N],tot,tt=-1,hh;
int vis[N],n,m;
void add(int a, int b, int c) {
    ver[++tot]=b;
    edge[tot]=c;
    Next[tot]=head[a];
    head[a]=tot;
}
void spfa() {
    q[++tt]=1;
    vis[1]=1;
    d[1]=0;
    while (hh<=tt) { // hh <= tt
        auto u=q[hh++];
        vis[u]=0; // remember set flag to false while removed from queue
        for (int i=head[u];i!=-1;i=Next[i]) {
            auto v=ver[i], w=edge[i];
            if (d[v]>d[u]+w) { // d[v] > d[u] + w
                d[v]=d[u]+w;
                if (!vis[v]) q[++tt]=v;
                vis[v]=1;
            }
        }
    }
    if (d[n] != 0x3f3f3f3f) { // != 0x3f3f3f3f
        cout<<"impossible"<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}
int main() {
    cin>>n>>m;
    memset(d, 0x3f, sizeof d);
    memset(head, -1, sizeof head);
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    return 0;
}

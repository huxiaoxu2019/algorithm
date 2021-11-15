#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int head[N],ver[N],Next[N],edge[N],tot;
int q[N],tt=-1,hh; // tt is -1, add operation will update tt index
int d[N],vis[N],cnt[N];
int n,m;
void add(int a,int b,int c) {
    ver[++tot]=b;
    edge[tot]=c;
    Next[tot]=head[a];
    head[a]=tot;
}
void spfa() {
    // need to initial all the point the graph
    for (int i=1;i<=n;++i) {
        q[++tt]=i;
        vis[i]=1;
    }
    while (hh<=tt) {
        auto u=q[hh++];
        vis[u]=0;
        for (int i=head[u];i!=-1;i=Next[i]) {
            auto v=ver[i], w=edge[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                cnt[v]=cnt[u]+1;
                if (vis[v]==0) q[++tt]=v;
                vis[v]=1;
                if (cnt[v]>=n) {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
}
int main() {
    memset(head, -1, sizeof head);
    cin>>n>>m;
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    return 0;
}

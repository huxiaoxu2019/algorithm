#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,fa[N];
struct Edge{
    int u, v, w;
    bool operator < (const Edge& a) const {
        return w<a.w;
    }
}edges[N];
int _find(int u) {
    if (fa[u] != u) return fa[u] = _find(fa[u]);
    return u;
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        edges[i].u=a, edges[i].v=b, edges[i].w=c;
    }
    sort(edges+1, edges+m+1);
    int cnt=0, ans=0;
    for (int i=1;i<=m;++i) {
        auto u=edges[i].u, v=edges[i].v, w=edges[i].w;
        auto pu=_find(u), pv=_find(v);
        if (pu == pv) continue;
        ans += w;
        fa[pv]=pu;
        ++cnt;
    }
    if (cnt < n - 1) {
        cout<<"impossible"<<endl;
    } else {
        cout<<ans<<endl;
    }
    return 0;
}

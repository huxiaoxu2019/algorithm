#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10, M=2e5+10;
int head[N], Next[M], ver[M], tot;
int vis[N], match[N], n1, n2, m, ans;
void add(int x, int y) {
    ver[++tot]=y; Next[tot]=head[x]; head[x]=tot;
}
bool dfs(int u) {
    for (int i=head[u];~i;i=Next[i]) {
        auto v=ver[i];
        if (!vis[v]) {
            vis[v]=1;
            if (match[v] == 0 || dfs(match[v])) {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin>>n1>>n2>>m;
    memset(head, -1, sizeof head);
    for (int i=0;i<m;++i) {
        int x, y;
        cin>>x>>y;
        add(x, y);
    }
    for (int i=1;i<=n1;++i) {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}

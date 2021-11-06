#include<bits/stdc++.h>
using namespace std;
const int N=6010;
int f[N][2];
int head[N], Next[N], ver[N], tot;
int n, happy[N];
bool vis[N]; // false no boss
void add(int u, int v) {
    ver[++tot]=v;
    Next[tot] = head[u];
    head[u] = tot;
}
void dfs(int u) {
    f[u][1] = happy[u];
    for (int i=head[u];i!=-1;i=Next[i]) {
        int v=ver[i];
        dfs(v);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
}
int main() {
    cin>>n;
    memset(head, -1, sizeof head);
    for (int i=1;i<=n;++i) {
        cin>>happy[i];
    }
    for (int i=1;i<=n-1;++i) {
        int a, b;
        cin>>a>>b;
        add(b, a);
        vis[a]=true;
    }
    int root=1;
    while (vis[root]) ++root;
    dfs(root);
    cout<<max(f[root][0], f[root][1])<<endl;
    return 0;
}

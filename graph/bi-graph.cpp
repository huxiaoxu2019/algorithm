#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10, M=2e5+10;
int head[N],Next[M],ver[M],tot;
int n,m,vis[N];
const int C=3;
void add(int a, int b) {
    ver[++tot]=b;
    Next[tot]=head[a];
    head[a]=tot;
}
bool dfs(int u, int color) {
    if (vis[u]) { 
        if (vis[u] != color) {
            return false;
        } else {
            return true;
        }
    }
    vis[u]=color;
    for (int i=head[u];~i;i=Next[i]) {
        int v=ver[i];
        if (!dfs(v, C-color)) {
            return false;
        }
    }
    return true;
}
int main() {
    cin>>n>>m;
    memset(head, -1, sizeof head);
    for (int i=0;i<m;++i) {
        int a,b;
        cin>>a>>b;
        add(a,b); add(b,a);
    }
    for (int i=1;i<=n;++i) {
        if (vis[i]) continue;
        if (!dfs(i, 1)) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}

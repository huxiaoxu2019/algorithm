#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10, M=2e5+10;
// be careful for M and N in the array
int Next[M], head[N], ver[M], tot;
int ans=INT_MAX,n,a,b,vis[M];
void add(int a, int b) {
    ver[++tot]=b;
    Next[tot]=head[a];
    head[a]=tot;
}
int dfs(int u) {
    // set true in vis
    vis[u]=1;
    int sum=1,cans=0;
    for (int i=head[u];i!=-1;i=Next[i]) {
        int v=ver[i];
        if (vis[v]) continue;
        int nsum=dfs(v);
        cans=max(cans, nsum);
        sum+=nsum;
    }
    cans=max(cans,n-sum);
    ans=min(ans, cans);
    return sum;
}
int main() {
    cin>>n;
    memset(head, -1, sizeof head);
    for (int i=0;i<n;++i) {
        cin>>a>>b;
        add(a,b); add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

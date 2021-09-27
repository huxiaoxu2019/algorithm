#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10, M=2*N;
int q[N], vis[N], head[N], Next[M], ver[M], tt=-1, hh, tot;
int n,m,a,b,step;
void add(int a, int b) {
    ver[++tot] = b;
    Next[tot] = head[a];
    head[a] = tot;
}
int main() {
    memset(head, -1, sizeof head);
    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        add(a,b);
    }
    vis[1]=1;
    q[++tt]=1;
    while (hh<=tt) {
        ++step;
        int cnt=tt-hh+1;
        while(cnt--) {
            auto u=q[hh++];
            for (int i=head[u];i!=-1;i=Next[i]) {
                int v=ver[i];
                if (vis[v]) continue;
                vis[v]=1;
                if (v==n) {
                    cout<<step<<endl;
                    return 0;
                }
                q[++tt]=v;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}

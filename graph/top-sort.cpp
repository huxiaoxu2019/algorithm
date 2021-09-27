#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2*N;
int head[N],Next[M],ver[M],tot;
// be careful for the hh and tt indices
int q[N],hh,tt=-1,n,m;
int a,b,d[N];
void add(int a, int b) {
    ver[++tot] = b;
    Next[tot] = head[a];
    head[a] = tot;
}
int main() {
    cin>>n>>m;
    memset(head, -1, sizeof head);
    while (m--) {
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    for (int i=1;i<=n;++i) {
        if (d[i]==0) q[++tt]=i;
    }

    while(hh<=tt) {
        auto u=q[hh++];
        for (int i=head[u];i!=-1;i=Next[i]) {
            auto v=ver[i];
            if (--d[v]==0) {
                q[++tt]=v;
            }
        }
    }
    if (tt+1==n) {
        for (int i=0;i<=tt;++i) {
            cout<<q[i]<<" ";
        }
    } else {
        cout<<"-1"<<endl;
    }

    return 0;
}

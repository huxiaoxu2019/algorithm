#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+10;
int d[N],backup[N],n,m,k;
struct Edge{
    int a,b,c;
}edges[M];
void bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1]=0;
    for (int i=0;i<k;++i) {
        memcpy(backup, d, sizeof d);
        for (int j=0;j<m;++j) {
            int a=edges[j].a, b=edges[j].b, c=edges[j].c;
            d[b]=min(d[b], backup[a]+c);
        }
    }
    if (d[n] > 0x3f3f3f3f/2) {
        cout<<"impossible"<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,c};
    }
    bellman_ford();
    return 0;
}

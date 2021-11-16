// store the relationship in union-find data structure, amazing
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,M=1e5+10;
int p[N],dis[N],n,k,d,x,y,ans;
int find(int x) {
    if (p[x]==x) return x;
    int px=find(p[x]);
    dis[x] += dis[p[x]];
    return p[x]=px;
}
void _union(int x, int y) {}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;++i) p[i]=i;
    for (int i=0;i<k;++i) {
        cin>>d>>x>>y;
        if (x>n||y>n) {++ans;continue;}
        if (d==2&&x==y) {++ans;continue;}
        int px=find(x), py=find(y);
        if (d==1) {
            if (px==py&&(dis[y]-dis[x])%3) {
                ++ans;
            } else if (px!=py) {
                p[px]=py;
                dis[px]=dis[y]-dis[x];
            }
        } else {
            if (px==py&&(dis[y]-dis[x]+1)%3) {
                ++ans;
            } else if (px!=py) {
                p[px]=py;
                dis[px]=dis[y]-dis[x]+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

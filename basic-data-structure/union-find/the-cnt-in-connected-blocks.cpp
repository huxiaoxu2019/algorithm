#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int p[N],cnt[N];
int n,m,x,y;
char op[2];
int find(int x) {
    if (p[x]) return p[x]=find(p[x]);
    return x;
}
void _union(int x, int y) {
    auto px=find(x), py=find(y);
    if (px==py) return;
    p[px]=py;
    cnt[py]+=cnt[px];
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;++i) cnt[i]=1;
    for (int i=0;i<m;++i) {
        cin>>op;
        if (op[0] == 'C') {
            cin>>x>>y;
            _union(x, y);
        } else if (op[1] == '1') {
            cin>>x>>y;
            if (find(x) == find(y)) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        } else {
            cin>>x;
            cout<<cnt[find(x)]<<endl;
        }
    }
    return 0;
}

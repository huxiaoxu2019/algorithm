#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,V;
struct good {
    int v, w;
} ;
vector<good> goods;
int f[N];
int main() {
    cin>>n>>V;
    for (int i=1;i<=n;++i) {
        int a, b, c, j;
        cin>>a>>b>>c;
        for (j=1;j<=c;j*=2) {
            goods.push_back({a*j, b*j});
            c-=j;
        }
        if (c) {
            goods.push_back({a*c, b*c});
        }
    }
    for (auto &g:goods) {
        for (int j=V;j>=g.v;--j) {
            f[j]=max(f[j], f[j-g.v]+g.w);
        }
    }
    cout<<f[V]<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,p[N];
int find(int x) {
    if (p[x] == 0) return x;
    return p[x] = find(p[x]);
}
void _union(int x, int y) {
    int px=find(x), py=find(y);
    if (px != py) p[px]=py;
}
int main() {
    cin>>n>>m;
    char op;
    int x,y;
    for (int i=0;i<m;++i) {
        cin>>op;
        cin>>x>>y;
        if (op == 'M') {
            _union(x, y);
        } else {
            int px=find(x), py=find(y);
            if (find(x) != find(y)) {
                
                cout<<"No"<<endl;
            } else {
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}

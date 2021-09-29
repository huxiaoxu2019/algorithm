#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int w[N],v[N],f[N];
int n,V;
int main() {
    cin>>n>>V;
    for (int i=1;i<=n;++i) {
        cin>>v[i]>>w[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=V;j>=v[i];--j) {
            f[j]=max(f[j], f[j-v[i]]+w[i]);
        }
    }
    cout<<f[V]<<endl;
    return 0;
}

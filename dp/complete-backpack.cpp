#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int w[N],v[N],n,V,f[N];
int main() {
    cin>>n>>V;
    for (int i=1;i<=n;++i) {
        int a,b;
        cin>>a>>b;
        v[i]=a; w[i]=b;
    }
    for (int i=1;i<=n;++i) {
        for (int j=v[i];j<=V;++j) {
            f[j]=max(f[j], f[j-v[i]]+w[i]);
        }
    }
    cout<<f[V]<<endl;
    return 0;
}

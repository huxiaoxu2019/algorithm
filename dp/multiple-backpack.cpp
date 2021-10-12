#include<bits/stdc++.h>
using namespace std;

int N,V,v[110],w[110],s[110],f[110];
int main() {
    cin>>N>>V;
    for (int i=1;i<=N;++i){
        cin>>v[i]>>w[i]>>s[i];
    }
    for (int i=1;i<=N;++i) {
        for (int j=V;j>=0;--j) {
            for (int k=0;k*v[i]<=j&&k<=s[i];++k) {
                f[j]=max(f[j],f[j-v[i]*k]+k*w[i]);
            }
        }
    }
    cout<<f[V]<<endl;
    return 0;
}

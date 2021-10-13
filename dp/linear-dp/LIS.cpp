#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],f[N],n;
int main() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    f[1]=1;
    int ans=1;
    for (int i=2;i<=n;++i) {
        f[i]=1;
        for (int j=1;j<i;++j) {
            if (a[i]>a[j]) f[i]=max(f[i],f[j]+1);
        }
        ans=max(f[i], ans);
    }
    cout<<ans<<endl;
    return 0;
}

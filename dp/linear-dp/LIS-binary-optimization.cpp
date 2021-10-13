#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n,q[N],len;
int main() {
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    q[0]=-2e9;
    for (int i=1;i<=n;++i) {
        int l=0,h=len,m;
        while(l<h) {
            m=(l+h+1)>>1;
            if (q[m]<a[i]) {
                l=m;
            } else {
                h=m-1;
            }
        }
        len=max(l+1, len);
        q[l+1]=a[i];
    }
    cout<<len<<endl;
    return 0;
}

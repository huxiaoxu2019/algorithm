#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N], q[N], tt=-1, hh;
int k, n;
int main() {
    cin>>n>>k;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        while (tt>=hh && a[q[tt]]>=a[i]) --tt;
        // hh, tt, i
        if (hh <= tt && i - q[hh] + 1 > k) ++hh;
        q[++tt]=i;
        if (i >= k - 1) cout<<a[q[hh]]<<" ";

    }
    cout<<endl;
    tt=-1,hh=0;
    for (int i=0;i<n;++i) {
        while (tt>=hh && a[q[tt]]<=a[i]) --tt;
        // hh, tt, i
        if (hh <= tt && i - q[hh] + 1 > k) ++hh;
        q[++tt]=i;
        if (i >= k - 1) cout<<a[q[hh]]<<" ";

    }
    cout<<endl;
    return 0;
}

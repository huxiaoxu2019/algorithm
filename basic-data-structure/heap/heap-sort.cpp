// be careful of the index of a[N]
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N]; // array of a for heap, index from 0. l(i)=2*i+1, r(i)=2*i+2, p(i)=(i-1)/2
int n,m;
void down(int u) {
    int t=u, l=2*u+1, r=2*u+2;
    while (l < n || r < n) {
        if (l < n && a[t]>a[l]) t=l;
        if (r < n && a[t]>a[r]) t=r;
        if (t == u) break;
        swap(a[t], a[u]);
        u=t;
        l=2*u+1; r=2*u+2;
    }
}

int main() {
    cin>>n>>m;
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }
    // build
    for (int i=n/2-1;i>=0;--i) {
        down(i);
    }
    for (int i=0;i<m;++i) {
        cout<<a[0]<<" ";
        a[0]=a[--n];
        down(0);
    }
    return 0;
}

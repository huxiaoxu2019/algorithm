// 非严格单调递增整型数组，找到目标值 T 在数组中出现的次数
// 二分 O(logn)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N], n, q, k;
typedef long long LL;
int findl(int k) {
    LL l=0,h=n-1,m;
    while (l<h) {
        m = l+h>>1;
        if (a[m] >= k) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int findr(int k) {
    LL l=0,h=n-1,m;;
    while (l<h) {
        m = l+h+1>>1;
        if (a[m] <= k) {
            l = m;
        } else {
            h = m - 1;
        }
    }
    return l;
}
int main() {
    cin>>n>>q;
    for (int i=0;i<n;++i) cin>>a[i];
    while (q--) {
        cin>>k;
        int lidx=findl(k), ridx=findr(k);
        if (a[lidx] != k) {
            cout<<"-1 -1"<<endl;
        } else {
            cout<<lidx<<" "<<ridx<<endl;
        }
    }
   return 0;
}

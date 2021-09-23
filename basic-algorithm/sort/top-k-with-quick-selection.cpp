// 找到第 k 大的数，O(n)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], k, n;
int quick_sort(int l, int h, int k) {
    if (l>=h) {
        return a[l];
    }
    int i=l-1,j=h+1,m=a[l+h>>1];
    while(i<j) {
        while(a[++i]<m);
        while(a[--j]>m);
        if (i<j) swap(a[i],a[j]);
    }
    int lcnt = j - l + 1;
    if (lcnt >= k) {
        quick_sort(l, j, k);
    } else {
        quick_sort(j+1, h, k - lcnt);
    }
}
int main() {
    cin>>n>>k;
    for (int i=0;i<n;++i) cin>>a[i];
    cout<<quick_sort(0, n - 1, k)<<endl;
    return 0;
}

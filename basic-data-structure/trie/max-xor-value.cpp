#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10; // be careful the N, is 26 * (1e5+10)
int son[N][2], tot; // tot from 1 index, current value is tail
int a[N],n,ans;
void insert(int x) {
    int p=0;
    for (int i=30;~i;--i) {
        int v=x>>i&1;
        if (son[p][v]) {
            p=son[p][v];
        } else {
            son[p][v]=++tot;
            p=tot;
        }
    }
}
int query(int x) {
    int p=0, ans=0;
    for (int i=30;~i;--i) {
        int v=x>>i&1;
        if (son[p][!v]) {
            p = son[p][!v];
            ans += (1<<i);
        } else {
            p = son[p][v];
        }
    }
    return ans;
}
int main() {
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        insert(a[i]);
    }
    for (int i=0;i<n;++i) {
        ans=max(ans, query(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}

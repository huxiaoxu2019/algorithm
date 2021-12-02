#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n, a[maxn], f[maxn];
int sg(int x) {
    if (f[x] != -1) return f[x];
    int ans = 0;
    unordered_set<int> st;
    for (int i=0;i<x;++i) {
        for (int j=0;j<=i;++j) {
            st.insert(sg(i) ^ sg(j));
        }
    }

    for (ans=0;;++ans) {
        if (st.count(ans) == 0) break;
    }

    return f[x] = ans;
}
int main() {
    memset(f, -1, sizeof f);
    cin>>n;
    for (int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for (int i=0;i<n;++i) {
        ans ^= sg(a[i]);
    }
    if (ans) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=131;
char str[N];
typedef unsigned long long LL;
int n,m,l1,r1,l2,r2;
LL p[N],h[N]; // p[i], i is for 131^i, i <= N, h[j], j is from index 1
LL getHash(int l, int r) {
    return h[r] - h[l-1]*p[r-l+1];
}
int main() {
    cin>>n>>m;
    p[0]=1;
    cin>>str;
    for (int i=1;i<N;++i) {
        p[i] = p[i-1]*M;
        h[i] = h[i-1]*M+str[i-1]; // h[i], i is from 1, for the edge case
    }
    for (int i=0;i<m;++i) {
        cin>>l1>>r1>>l2>>r2;
        if (getHash(l1,r1)==getHash(l2,r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

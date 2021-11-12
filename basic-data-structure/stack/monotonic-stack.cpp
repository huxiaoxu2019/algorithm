#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N], tt=0; // from index 1, q[tt] = value
int n, t;
int main() {
    cin>>n;
    while (n--) {
        cin>>t;
        while (tt && q[tt] >= t) --tt;
        if (tt) {
            cout<<q[tt]<<" ";
        } else {
            cout<<"-1 ";
        }
        q[++tt] = t;
    }
    return 0;
}

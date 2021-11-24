#include<bits/stdc++.h>
using namespace std;
// input n, a, b, 求 C(a,b)
int n,a,b;
const int N=2e3+10;
int mod=1e9+7;
int C[N][N];
void init() {
    for (int i=0;i<N;++i) {
        C[i][0]=1;
        for (int j=1;j<=i;++j) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
}
int main() {
    cin>>n;
    init();
    while (n--) {
        cin>>a>>b;
        cout<<C[a][b]<<endl;
    }
    return 0;
}

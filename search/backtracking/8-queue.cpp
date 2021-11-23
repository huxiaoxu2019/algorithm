#include<bits/stdc++.h>
using namespace std;
// input n for size of col and row
// output total number of solutions
int n,tot,vis[3][100]; // 0 for col, 1 for main diagonal, 2 for anti-diagonal
void solve(int r) {
    if (r == n + 1) {
        tot++;
        return ;
    }
    for (int c=1;c<=n;++c) {
        if (vis[0][c] || vis[1][r-c] || vis[2][r+c]) continue;
        vis[0][c]=vis[1][r-c]=vis[2][r+c]=1;
        solve(r+1);
        vis[0][c]=vis[1][r-c]=vis[2][r+c]=0;
    }
}
int main() {
    cin>>n;
    solve(1);
    cout<<tot<<endl;
    return 0;
}


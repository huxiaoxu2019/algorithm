#include<bits/stdc++.h>
using namespace std;
// dp(i) 从 i 出发的最长距离值
const int N = 310;
int f[N][N], g[N][N];
int R, C;
int d[5] = {1, 0, -1, 0, 1}; // down, left, up, right
int ans=0;
int dp(int r, int c) {
    if (f[r][c]) return f[r][c];
    int cans = 1;
    for (int di=0;di<4;++di) {
        int nr=r+d[di], nc=c+d[di+1];
        if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if (g[nr][nc] >= g[r][c]) continue;
        cans = max(cans, 1 + dp(nr, nc));
    }
    return f[r][c] = cans;
}
int main() {
    cin>>R>>C;
    for (int r=1;r<=R;++r) {
        for (int c=1;c<=C;++c) {
            cin>>g[r][c];
        }
    }
    for (int r=1;r<=R;++r) {
        for (int c=1;c<=C;++c) {
            ans=max(ans, dp(r, c));
        }
    }
    cout<<ans<<endl;
    return 0;
}

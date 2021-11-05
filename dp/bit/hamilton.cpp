#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int f[N][21];
int  n, a[21][21];
// f[i][j] 从 1  到 j 点，且经过{i}集合中的点的情况，的最小路径值
// 状态计算 由什么状态递推出来
// f[i][j] = min{f[i-j][k] + a[k][j]}
// k in {i} && k != j
int main() {
    cin >> n;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            cin>>a[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    // 初始状态
    f[1][1] = 0;
    for (int i=0;i<(1<<n);++i) {
        for (int j=1;j<=n;++j) {
            if ((1<<j-1&i) == 0) continue;
            for (int k=1;k<=n;++k) {
                if ((1<<k-1&i)==0) continue;
                if (k == j) continue;
                f[i][j] = min(f[i][j], f[i - (1<<(j-1))][k] + a[k][j]);
            }
        }
    }
    cout<<f[(1<<n)-1][n]<<endl;
    return 0;
}

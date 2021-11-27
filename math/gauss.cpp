// Not AC
// https://leetcode-cn.com/playground/ryTfJBRg/
#include<bits/stdc++.h>
using namespace std;
double g[110][110];
const double eps = 1e-6;
int main () {
    cin>>n;
    for (int r=1;r<=n;++r) {
        for (int c=1;c<=n+1;++c) {
            cin>>g[r][c];
        }
    }
    int r, c;
    for (r=1,c=1;r<=n;++r,++c) {
        int t=r;
        for (int rr=r+1;rr<=n;++rr) {
            if (g[rr][c] > g[r][c]) {
                t=rr;
            }
        }

        if (fasb(g[t][c]) < eps) continue;

        for (int i=c;i<=n+1;++c) swap(g[t][i], g[r][i]);
        
        double k=g[r][c];
        for (int i=c;i<=n+1;++c) g[r][i] /= k;

        for (int rr=r+1;rr<=n;++rr) {
            for (int cc=c;cc<=n+1;++cc) {
                g[rr][cc] = g[rr][cc] - g[r][cc] * g[rr][c];
            }
        }
    }

    if (r<=n) {
        for (int i=r;i<=n;++i) {
            if (fabs(g[i][n+1])>eps) {
                // 无解
                cout<<"No solution"<<endl;
                return 0;
            }
        }
        // 有无穷解
        cout<<"Infinite group solutions"<<endl;
        return 0;
    } else {
        // 有唯一解
        g[n][n+1] /= g[n][n];
        for (int rr=n-1;rr>=1;--rr) {
            for (int cc=rr+1;cc<=n;++cc) {
                g[rr][n+1] = g[rr][n+1] - g[rr+1][n+1] * g[rr][cc];
            }
        }
        for (int rr=1;rr<=n;++rr) printf("%.2lf\n", a[rr][n+1]);
    }

    return 0;
}

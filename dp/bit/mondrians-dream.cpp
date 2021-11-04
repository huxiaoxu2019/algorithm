#include<bits/stdc++.h>
using namespace std;
const int N=12,M=1<<12;
typedef long long LL;
int n,m;
LL f[N][M];
vector<int> p[M];
int main() {
    cin>>n>>m;
    while (n != 0 && m != 0) {
        for (int i=0;i<(1<<n);++i) {
            p[i].clear();
            for (int j=0;j<(1<<n);++j) {
                if (i&j) continue;
                bool valid=true;
                int cnt=0;
                for (int k=0;k<n;++k) {
                    if (i&(1<<k) || j&(1<<k)) {
                        if (cnt & 1) {
                            valid = false;
                            break;
                        }
                        cnt = 0;
                    } else {
                        ++cnt;
                    }
                }
                if (cnt & 1) {
                    valid = false;
                    }
                if (valid) {
                    p[i].push_back(j);
                }
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                for (auto k : p[j]) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
        cin>>n>>m;
    }
    return 0;
}

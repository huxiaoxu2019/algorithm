#include<bits/stdc++.h>
using namespace std;
// 3 个集合 : S1, S2, S3
// 全集 = S1 + S2 + S3 - S1S2 - S2S3 - S1S3 + S1S2S3
// 时间复杂度：O(2^n) n 为集合的个数
// C(0,3) + C(1,3) + C(2,3) + C(3,3) = 2 ^ n
typedef long long LL;
int n,m,p[20],ans;
int main() {
    cin>>n>>m;
    for (int i=0;i<m;++i) cin>>p[i];

    for (int s=1;s<(1<<m);++s) {
        int cnt=0, t=1;
        for (int i=0;i<m;++i) {
            if ((s >> i) & 1) {
                if ((LL)t * p[i] > n) {
                    t = -1;
                    break;
                }
                ++cnt;
                t = t * p[i];
            }
        }
        if (t != -1) {
            if (cnt % 2) ans += n / t;
            else ans -= n / t;
        }

    }


    cout<<ans<<endl;
    return 0;
}



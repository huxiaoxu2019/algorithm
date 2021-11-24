// 筛素数
// 素数定理 π(1e7) = 664579
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1e6+10;
int st[N],prime[N],cnt;
int n;
void getPrimes(int n) {
    // 埃及筛法 O(nlogn)
    for (ULL i=2;i<=n;++i) {
        if (!st[i]) {
            prime[++cnt]=i;
            // i    2*i     3*i     4*i
            // i^2  2*i^2   3*i^2   4*i^2 变形：筛“无平方因子”的数
            for (ULL j=i*i;j<=n;j+=i) st[j]=1;
        }
    }
    cout<<cnt<<endl;
}
// 线性筛法 - 每一个质数用最小的质因子筛掉
void getPrimes2(int n) {
    for (int i=2;i<=n;++i) {
        if (!st[i]) prime[++cnt]=i;
        for (int j=1;prime[j]*i<=n;++j) { // just check prime[j]*i <= n
            st[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
    cout<<cnt<<endl;
}
int main() {
    cin>>n;
    getPrimes(n);
    return 0;
}

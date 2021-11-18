#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int st[N],prime[N],cnt;
int n;
void getPrimes(int n) {
    // 埃及筛法
    for (int i=2;i<=n;++i) {
        if (!st[i]) {
            prime[++cnt]=i;
            for (int j=prime[cnt];j<=n;j+=prime[cnt]) {
                st[j]=true;
            }
        }
    }
    cout<<cnt<<endl;
}
// 线性筛法 - 每一个质数用最小的质因子筛掉
void getPrimes2(int n) {
    for (int i=2;i<=n;++i) {
        if (!st[i]) prime[++cnt]=i;
        for (int j=1;prime[j]*i<=n;++j) {
            st[prime[j]*i]=true;
            if (i%prime[j]==0) break;
        }
    }
    cout<<cnt<<endl;
}
int main() {
    cin>>n;
    getPrimes2(n);
    return 0;
}

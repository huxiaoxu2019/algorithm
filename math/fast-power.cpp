// 费马小定理 https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
// b 与 p 互质，则有 b^(p-1)与1同余，在模p的情况下
// b*b^(p-2)与1同余，则b^(p-2)为逆元
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL fast_power(int a, int k, int q) {
    LL res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % q;
        k>>=1;
        a = (LL)a * a % q;
    }
    return res;
}
int main() {
    int a, k, q;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &k, &q);
        cout<<fast_power(a,k,q)<<endl;
    }
    return 0;
}

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

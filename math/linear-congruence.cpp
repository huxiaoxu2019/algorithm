#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// ax ≡ b (mod m)
// xa + ym = b
// gcd(a,m) 能整除 b，则有解
// x * (b / gcm(a,m))
using namespace std;
int n,a,b,m;
int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x=1;y=0;
        return a;
    } else {
        auto d = exgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
}
int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        auto d=exgcd(a, m, x, y);
        if (b%d) {
            puts("impossible");
        } else {
            printf("%d\n", (LL)x * (b / d) % m);
        }
    }
    return 0;

}

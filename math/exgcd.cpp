#include<bits/stdc++.h>
using namespace std;
// 裴蜀定理
//
// xa+yb=gcd(a,b)
// if b == 0, then x=1,y=0
// else gcd(a,b) = gcd(b, a%b, y, x)
// yb + x(a-a/b*b)=gcd(a,b)=d
// xa + (y - a/b*x)b = d
// y = y - a/b*x
int n,a,b;
int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x=1,y=0;
        return a;
    } else {
        auto d = exgcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
}
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        int x,y;
        exgcd(a, b, x, y);
        cout<<x<<" "<<y<<endl;
    }
    return 0; 
}

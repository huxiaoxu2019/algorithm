#include<bits/stdc++.h>
using namespace std;
// delta to be smaller than required accuracy(1e-6)
double a, delta=1e-8;
int l,h,m;
int main() {
    cin>>a;
    l=-10000,h=10000;
    while (h-l>delta) {
        m = (l + h) / 2;
        if (m * m * m > a) {
            h = m;
        } else {
            l = m;
        }
    }
    printf("%.6f\n", l);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a;
void solve(int x) {
    LL ans=x;
    for (int i=2;i<=x/i;++i) {
        if (x%i==0) {
            ans=ans/i*(i-1);
            while (x%i == 0) x/=i;
        }
    }
    if (x>1) ans = ans / x * (x-1);
    cout<<ans<<endl;
}
int main() {
    cin>>n;
    while (n--) {
        cin>>a;
        solve(a);
    }
    return 0;
}

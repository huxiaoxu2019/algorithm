#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
int n, a;
unordered_map<int, int> prime;
LL sum=1;
int main() {
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a;
        for (int j=2;j<=a/j;++j) {
            while (a%j==0) {
                prime[j]++;
                a/=j;
            }
        }
        if (a>1) prime[a]++;
    }
    for (auto& x:prime) {
        sum *= (1 + x.second);
        sum %= MOD;
    }
    cout<<sum<<endl;
    return 0;
}

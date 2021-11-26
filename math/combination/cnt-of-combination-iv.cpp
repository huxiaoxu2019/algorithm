#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int primes[1000], pi=-1;
int st[5010];
int sum[N];
void getPrimes() {
    for (int i=2;i<=N;++i) {
        if (!st[i]) primes[++pi]=i;
        for (int j=0;primes[j]<=N/i;++j) {
            st[primes[j]*i]=1;
            if (i%primes[j] == 0) break;
        }   
    }
}

int get(int a, int p) {
    int ans = 0;
    while (a) {
        ans += a / p;
        a /= p;
    }
    return ans;
}

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t=0;
    for (int i=0;i<a.size();++i) {
        t = t + b * a[i];
        c.push_back(t%10);
        t /= 10;
    }
    while (t) {
        c.push_back(t%10);
        t/=10;
    }
    return c;
}

int main() {
    int a,b;
    cin>>a>>b;
    
    getPrimes();
    for (int i=0;i<=pi;++i) {
        int p=primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a-b, p);
    }
    vector<int> ans={1};
    for (int i=0;i<=pi;++i) {
        for (int j=0;j<sum[i];++j) {
            ans = mul(ans, primes[i]);
        }
    }

    for (int i=ans.size()-1;i>=0;--i) cout<<ans[i];
    return 0;
}

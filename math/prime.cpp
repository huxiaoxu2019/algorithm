// https://blog.csdn.net/zzzanj/article/details/81260098
#include<bits/stdc++.h>
using namespace std;
// O(n) 欧拉筛法 线性
const long long maxn=1e8+1;
long long prime[maxn];
bool sf[maxn]; // suffix for prime
void table() {
    long long num=0;
    memset(sf, true, sizeof sf);
    sf[1] = false;
    sf[0] = false;
    for (int i=2;i<=maxn;++i) {
        if (sf[i]) prime[++num]=i;
        for (int j=1;j<=num;++j) {
            if (i*prime[j]>maxn) break;
            sf[i*prime[j]]=false;
            if (i%prime[j] == 0) break;
        }
    }
}

int main() {
    return 0;
}


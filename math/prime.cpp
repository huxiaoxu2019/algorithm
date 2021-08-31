// https://blog.csdn.net/zzzanj/article/details/81260098
#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+1;
long long prime[maxn];
bool st[maxn];
long long cnt=0;

// O(n) 欧拉筛法
void table() {
    for (int i=2;i<=maxn;++i) {
        if (!st[i]) prime[++cnt]=i;
        for (int j=1;j<=cnt;++j) {
            if (i*prime[j]>maxn) break;
            st[i*prime[j]]=true;
            if (i%prime[j] == 0) break;
        }
    }
}


// 埃及筛法 O(nloglogn)
void table_2() {
    for (int i = 2; i <= maxn; ++i) {
        if (!st[i]) {
            prime[++cnt] = i;
            for (int j = i; j <= maxn; j += i) {
                st[j] = true;
            }
        }
    }
}

int main() {
    table_2();
    for (int i=1;i<=10;++i) cout<<prime[i]<<endl;
    return 0;
}

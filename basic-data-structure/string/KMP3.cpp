#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m, Next[N];
string s,p; // n = s.size(), m = p.size()
vector<int> ans;
void getNext() {
    // be careful the limit var(n), not m
    for (int i=0,j=1;j<n;++j) {
        while (i > 0 && p[i] != p[j]) i=Next[i-1];
        if (p[i] == p[j]) ++i;
        Next[j] = i;
    }
}
void kmp() {
    for (int i=0,j=0;i<m;++i) {
        while (j > 0 && s[i] != p[j]) j = Next[j-1];
        if (s[i] == p[j]) ++j;
        if (j == n) {
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            ans.push_back(i - n + 1);
            j = Next[j - 1];
        }
    }
}


int main() {
    cin>>n>>p>>m>>s;
    getNext();
    kmp();
    for (auto c : ans) cout << c << " ";
    return 0;
}

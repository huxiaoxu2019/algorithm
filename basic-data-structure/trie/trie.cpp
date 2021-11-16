#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int son[N][26], tot; // tot from index 1, current is tail
int cnt[N];
char op;
int n;
void insert(string& str) {
    int p=0;
    for (auto& c:str) {
        int idx=c-'a';
        if (son[p][idx]) {
            p=son[p][idx];
        } else {
            son[p][idx]=++tot;
            p=tot;
        }
    }
    cnt[p]++;
}
int query(string& str) {
    int p=0;
    for (auto& c:str) {
        int idx=c-'a';
        if (son[p][idx]) {
            p = son[p][idx];
        } else {
            return 0;
        }
    }
    return cnt[p];
}
int main() {
    cin>>n;
    string str;
    for (int i=0;i<n;++i) {
        cin>>op>>str;
        if (op == 'I') {
            insert(str);
        } else {
            cout<<query(str)<<endl;
        }
    }
    return 0;
}

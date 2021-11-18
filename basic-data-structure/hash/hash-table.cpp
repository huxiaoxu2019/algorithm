#include<bits/stdc++.h>
using namespace std;
const int N=100003;
int he[N],ne[N],ver[N],tot;
int n;
void insert(int x) {
    int h=(x%N+N)%N;
    ver[++tot]=x;
    ne[tot]=he[h];
    he[h]=tot;
}
void find(int x) {
    int h=(x%N+N)%N;
    for (int i=he[h];i!=-1;i=ne[i]) {
        int v=ver[i];
        if (v==x) {
            cout<<"Yes"<<endl;
            return ;
        }
    }
    cout<<"No"<<endl;
}
int main() {
    memset(he, -1, sizeof he);
    cin>>n;
    for (int i=0;i<n;++i) {
        char op; int x; // be careful the type of x, is not char...
        scanf("%s%d", &op, &x);
        if (op == 'I') {
            insert(x);
        } else {
            find(x);
        }
    }
    return 0;
}

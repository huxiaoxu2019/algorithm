#include<bits/stdc++.h>
using namespace std;
int n, st[1e5+10], idx; // idx from 1 to n, current idx is tail
void push(int v) {
    st[++idx] = v;
}

int top() {
    return st[idx];
}

void pop() {
    if (idx > 0) --idx;
}

bool empty() {
    return idx==0;
}

int main() {
    cin>>n;
    string op;
    while (n--) {
        cin>>op;
        if (op == "push") {
            int v;
            cin>>v;
            push(v);
        } else if (op == "query") {
            cout<<top()<<endl;
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            if (empty()) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

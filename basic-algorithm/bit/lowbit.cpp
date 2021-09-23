#include<bits/stdc++.h>
using namespace std;
int n, a, cnt;
int main() {
    cin>>n;
    while (n--) {
        cin>>a;
        cnt = 0;
        while (a) {
            a -= a & (-a);
            ++cnt;
        }
        cout<<cnt<<" ";
    }
}

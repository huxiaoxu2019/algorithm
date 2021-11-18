#include<bits/stdc++.h>
using namespace std;
int n, a;
vector<int> ans;
int main() {
    cin>>a;
    while(a--) {
        cin>>n;
        ans.clear();
        for (int i=1;i<=n/i;++i) {
            if (n%i==0) {
                ans.push_back(i);
                if (n/i !=  i) ans.push_back(n/i);   
            }    
            
        }
        sort(ans.begin(), ans.end());
        for (auto& x: ans) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

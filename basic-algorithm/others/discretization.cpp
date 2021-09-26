#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,x,c,l,r,b[N];
unordered_map<int,int> hm;
vector<int> nums;
int query(int x) {
    int res = 0;
    for (;x>0;x -= x & (-x)) {
        res += b[x];
    }
    return res;
}
void update(int x, int d) {
    for (;x<=N;x += x & (-x)) {
        b[x] += d;
    }
}
int findIdx(int x) {
    int l = 0, h = nums.size() - 1, m;
    while (l < h) {
        m = l + h >> 1;
        if (nums[m] >= x) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int main() {
    cin>>n>>m;
    while (n--) {
        cin>>x>>c;
        hm[x]+=c;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i=0;i<nums.size(); ++i) {
        update(i+1, hm[nums[i]]);
    }

    while (m--) {
        cin>>l>>r;
        int lidx=findIdx(l), ridx=findIdx(r);
        if (nums[lidx] < l) ++lidx;
        if (nums[ridx] > r) --ridx;
        cout<<query(ridx + 1) - query(lidx)<<endl;
    }

    return 0;
}

//
// Created by huxiaoxu on 2020/9/16.
//
// https://oi-wiki.org/dp/number/
int dfs(int x, int st, int op)  // op=1 =;op=0 <
{
    if (!x) return 1;
    if (!op && ~f[x][st]) return f[x][st];
    int maxx = op ? dim[x] : 9, ret = 0;
    for (int i = 0; i <= maxx; i++) {
        if (abs(st - i) < 2) continue;
        if (st == 11 && i == 0)
            ret += dfs(x - 1, 11, op & (i == maxx));
        else
            ret += dfs(x - 1, i, op & (i == maxx));
    }
    if (!op) f[x][st] = ret;
    return ret;
}
int solve(int x) {
    memset(f, -1, sizeof f);
    dim.clear();
    dim.push_back(-1);
    int t = x;
    while (x) {
        dim.push_back(x % 10);
        x /= 10;
    }
    return dfs(dim.size() - 1, 11, 1);
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
struct edge{
    int l, r;
}tr[N << 2];
vector <int> e[N];
bool f[N << 2];
int siz[N];
int n, cnt = 0, ans = 1e16;
int onepre[N << 2], zeropre[N << 2], onesuf[N << 2], zerosuf[N << 2];
void dfs(int u) {
    if(!u) return;
    siz[u] = 1;
    dfs(tr[u].l);
    dfs(tr[u].r);
    siz[u] += siz[tr[u].l] + siz[tr[u].r];
    if(siz[tr[u].l] < siz[tr[u].r]) swap(tr[u].l, tr[u].r);
}
void dfs1(int u, int idx) {
    if(!u) return ;
    f[idx] = true;
    if(cnt < idx) cnt = idx;
    dfs1(tr[u].l, idx * 2);
    dfs1(tr[u].r, idx * 2 + 1);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        if(a != 0) tr[i].l = a;
        if(b != 0) tr[i].r = b;
    }
    dfs(1);
    dfs1(1, 1);
    int sum;
    for(int i = 1; i <= cnt + 1; i ++) sum += f[i];
    for(int i = 1; i <= cnt + 1; i ++) {
        onepre[i] = onepre[i - 1] + f[i];
        onesuf[i] = sum - onepre[i];
        zeropre[i] = zeropre[i - 1] + (!f[i]);
        zerosuf[i] = cnt + 1 - sum - zeropre[i];
        ans = min(ans, zeropre[i] + onesuf[i]);
    }
    // for(int i = 1; i <= cnt + 1; i ++) cerr << f[i] << " \n"[i == cnt + 1];
    // for(int i = 1; i <= cnt + 1; i ++)
        // cerr << onepre[i] << '/' << onesuf[i] << '/' << zeropre[i] << '/' << zerosuf[i] << ' ';
    cout << ans;
    
    return 0;
}
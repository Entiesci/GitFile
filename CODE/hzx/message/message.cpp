
#include <bits/stdc++.h>
#include <queue>
#define rep(l, r, i) for (int i = l, END##i = r; i <= END##i; ++i)
#define per(r, l, i) for (int i = r, END##i = l; i >= END##i; --i)
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int, int>
#define ps second
#define pf first

#define X(j) i[j]
#define Y(j) (dp[j] + (i[j] + L) * (i[j] + L))

#define rd read()
int read() {
    int xx = 0, ff = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
		if (ch == '-')
			ff = -1;
		ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
      xx = xx * 10 + (ch - '0'), ch = getchar();
    return xx * ff;
}
void write(int out) {
	if (out < 0)
		putchar('-'), out = -out;
	if (out > 9)
		write(out / 10);
	putchar(out % 10 + '0');
}

const int N = 5e5 + 5;
const int INF = 1e18;

int n,mxd;

void dfs(int x,int fa){
	dep[x]=dep[fa];
	if(t[x].a)dfs(t[x].a,x);
	if(t[x].b)dfs(t[x].b,x);
	cnt[dep[x]]++;
	mxd=max(mxd,dep[x]);
}
void solve()
{
	n=rd;
	for(int i=1;i<=n;i++){
		t[i].a=rd;
		t[i].b=rd;
		if(!t[i].a)swap(t[i].a,t[i].b);//尽量往左边丢
	}
	dfs(1,0);

	for(int i=1;i<=mxd;i++){
		qz[i]=qz[i-1]+cnt[i];
	}
	for(int h=1;h<=mxd;h++){
		ans=qz[mxd]-qz[h];//删除下面
		ans+=(1<<h)-1-qz[h-1];//补齐上面
		
	}
}
signed main() {
    int T=1;
    while(T--){
    	solve();
    }
    return 0;
}


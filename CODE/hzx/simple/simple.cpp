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

const int N = 3e5 + 5;
const int INF = 1e18;
int n;
int a[N];


void cal(int l,int r){
    int ans=0;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            ans^=(a[i]+a[j]);
        }
    }
    cout<<ans<<endl;
}
void solve(){
    int n=rd,m=rd;
    for(int i=1;i<=n;i++){
        a[i]=rd;
    }
    while(m--){
        int l=rd,r=rd;
        cal(l,r);
    }
}

signed main() {
    int T=1;
    while(T--){
    	solve();
    }
    return 0;
}



#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define rep(i, l, r) for (int i = l, END##i = r; i <= END##i; ++i)
#define per(i, r, l) for (int i = r, END##i = l; i >= END##i; --i)
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int, int>
#define ps second
#define pf first

#define rd read()
int read(){
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

const bool enable_dbg = true;
template <typename T,typename... Args>
void dbg(bool flg,T s,Args... args) {
	if constexpr (enable_dbg){
		cout << s;
		if constexpr (sizeof...(Args))
			dbg(flg,args...);
	}
}

const int N = 2e6 + 5;
const int INF = 1e18;
const int M = 1e7;
int MOD = 1e9 + 7;


int n;
string s;

void solve(){
    n=rd;
    cin>>s;

}

signed main() {
    int T=1;
    while(T--){
    	solve();
    }
    return 0;
}
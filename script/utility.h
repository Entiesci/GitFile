


#define mp make_pair
#define pii pair<int,int>
#define pb push_back

namespace fastOI{
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

}using namespace fastOI;



namespace CDBG{
	#define cdbg(x...) do { cerr << #x << " -> "; err(x); } while (0)
	void err() { cerr << endl; }
	template<template<typename...> class T, typename t, typename... A>
	void err(T<t> a, A... x) { for (auto v: a) cerr << v << ' '; err(x...); }
	template<typename T, typename... A>
	void err(T a, A... x) { cerr << a << ' '; err(x...); }
}using namespace CDBG;



namespace LCA{
	int dep[N];
	int fa[22][N];
	void dfs(itn x,int f){
		dep[x]=dep[f]+1;
		for(auto v:e[x]){
			if(v==f)continue;
			fa[0][v]=x;
			for(int i=1;i<=20;i++){
				fa[i][v]=fa[i-1][fa[i-1][v]];
			}
			
			dfs(v,x);
		}
	}
	
	int lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;~i;i--){
			if(dep[fa[i][a]]>=dep[b])a=fa[i][a];
		}
		if(a==b)return a;
		for(int i=20;~i;i--){
			if(fa[i][b]!=fa[i][a]){
				a=fa[i][a];
				b=fa[i][b];
			}
		}
		return fa[0][a];
	}
}using namespace LCA;

namespace UNI{
	int pa[N];
	
	int find(int x){
		if(pa[x]==x)return x;
		return pa[x]=find(pa[x]);
	}
	
	void join(int a,int b){
		int faa=find(a);
		int fbb=find(b);
		if(faa==fbb)return ;
		pa[faa]=fbb;
	}
}using namespace UNI;

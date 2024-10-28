


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


namespace BIT{
	int c[N];
	inline int lowbit(int x){
		return x&-x;
	}
	int query(int x){
		int res=0;
		while(x){
			res+=c[x];
			x-=lowbit(x);
		}
		return res;
	}
	void change(int x,int v){
		while(x<N){
			c[x]+=v;
			x+=lowbit(x);
		}
	}
}using namespace BIT;


namespace SGT{
	struct Node{
		
	}t[N<<2];
	int tag[N<<2];
	
	Node merge(Node a,Node b){
		
	}
	
	void pushup(int x){
		t[x]=merge(t[x<<1],t[x<<1|1]);
	}
	
	void addtag(int x,itn c){
		
	}
	
	void pushdown(int x){
		if(tag[x]){
			addtag(x<<1,tag[x]);
			addtag(x<<1|1,tag[x]);
			tag[x]=0;
		}
	}
	
	void change(int x,int l,int r,int pl,int pr,int v){
		if(pl<=l&&pr>=r){
			addtag(x,v);
			return ;
		}
		pushdown(x);
		int mid=l+r>>1;
		if(pl<=mid)change(x<<1,l,mid,pl,pr,v);
		if(pr>mid)change(x<<1|1,mid+1,r,pl,pr,v);
		pushup(x);
		
	}
	
	
	Node query(itn x,int l,int r,int pl,itn pr){
		if(pl<=l&&pr>=r){
			return t[x];
		}
		pushdown(x);
		int fl=0,fr=0;
		Node nl,nr;
		int mid=l+r>>1;
		if(pl<=mid)fl=1,nl=query(x<<1,l,mid,pl,pr);
		if(pr>mid)fr=1,nr=query(x<<1|1,mid+1,r,pl,pr);
		if(fl+fr==1){
			if(fl)return nl;
			return nr;
		}
		return merge(nl,nr);
	}
	
	
	void build(itn x,int l,int r){
		if(l==r){
			
			return ;
		}
		int mid=l+r>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		pushup(x);
	}
}using namespace SGT;




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

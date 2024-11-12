// Problem: A. 地雷爆炸
// Contest: undefined - NOIP2024训练赛 02
// URL: http://noi.ac/contest/1154/problem/2053
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Challenger: Erica N
// ----
// 
#include<bits/stdc++.h>

using namespace std;
#define rd read()
#define ull unsigned long long
#define int long long 
#define pb push_back
#define itn int
#define ps second 
#define pf first


#define rd read()
int read(){
  int xx = 0, ff = 1;char ch = getchar();
  while (ch < '0' || ch > '9'){
    if (ch == '-')ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')xx = xx * 10 + (ch - '0'), ch = getchar();
  return xx * ff;
}
#define zerol = 1
#ifdef zerol
#define cdbg(x...) do { cerr << #x << " -> "; err(x); } while (0)
void err() {cerr << endl;}
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
	for (auto v: a) cerr << v << ' ';err(x...);
}
template<typename T, typename... A>
void err(T a, A... x) {
	cerr << a << ' ';err(x...);
}
#else
#define dbg(...)
#endif
const int N=3e2+5;
const ull P=137;
const int INF=1e18+7;
/*

策略


*/	


double p[N],sp;
double f[N][N];
signed main(){
	int n=rd,m=rd;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	
	
	f[m][0]=1;
	for(int i=m-1;~i;i--){
		f[i][0]=1;
		for(int j=0;j<=n;j++){
			f[i][1]+=f[i+1][j]*p[j];
		}
		
		for(int j=2;j<=n;j++){
			f[i][j]=f[i][j-1]*f[i][1];
		}
	}
	
	
	printf("%.4lf",f[0][1]);
	
	
}

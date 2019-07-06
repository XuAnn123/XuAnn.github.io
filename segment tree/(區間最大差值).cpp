#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
int st_max[4*maxn],st_min[4*maxn];

void build(int l,int r ,int node){
	if(l == r){
		scanf("%d",&st_max[node]);
		st_min[node] = st_max[node];
		return;
	}
	int m = (l+r)/2;
	build(l,m,node*2);
	build(m+1,r,node*2+1);
	st_max[node] = max(st_max[node*2],st_max[node*2+1]);
	st_min[node] = min(st_min[node*2],st_min[node*2+1]);
}

int query_max(int ql,int qr,int l,int r,int node){
	if(ql <= l && qr  >=r) return st_max[node];
	int mid = (l+r)/2;
	int _max = 0;
	if(ql <= mid) _max = max(_max,query_max(ql,qr,l,mid,node*2));
	if(qr >  mid) _max = max(_max,query_max(ql,qr,mid+1,r,node*2+1));
	return _max;
}

int query_min(int ql,int qr,int l,int r,int node){
	if(ql <= l && qr >= r) return st_min[node];
	int mid = (l+r)/2;
	int _min = 2147483647;
	if(ql <= mid) _min = min(_min,query_min(ql,qr,l,mid,node*2));
	if(qr >  mid) _min = min(_min,query_min(ql,qr,mid+1,r,node*2+1));
	return _min;
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q) !=EOF){
		build(1,n,1);
		while(q--){
			int a,b;
			scanf("%d%d",&a,&b);
			int mx = query_max(a,b,1,n,1),mi = query_min(a,b,1,n,1);
			printf("%d\n",mx-mi);
		}
	}
	
}

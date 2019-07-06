#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int st[maxn*4];//存區間最大值 

void build(int l,int r,int node){
	if(l == r){
		scanf("%d",&st[node]);
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	st[node] = max(st[node*2],st[node*2+1]);
}

void update(int pos,int val,int l,int r,int node){
	if(l == r){
		st[node] = val;
		return;
	}
	int mid = (l+r)/2;
	if(pos <= mid) update(pos,val,l,mid,2*node);
	else update(pos,val,mid+1,r,node*2+1);
	st[node] = max(st[2*node],st[node*2+1]);
}

int query_max(int ql,int qr,int l,int r,int node){
	if(ql <= l && qr >= r)	return st[node];
	int mid = (l+r)/2;
	int ans = 0;
	if(ql <= mid) ans = max(ans,query_max(ql,qr,l,mid,node*2));
	if(qr >  mid) ans = max(ans,query_max(ql,qr,mid+1,r,node*2+1));
	return ans;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		build(1,n,1);
		char s;
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%c%d%d",&s,&a,&b);
			if(s == 'Q')
				printf("%d\n",query_max(a,b,1,n,1));
			if(s == 'U')	
				update(a,b,1,n,1);
		}	
	}
}
	

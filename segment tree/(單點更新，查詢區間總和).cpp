#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn = 5e4+5;
int st[4*maxn];

void build(int l,int r,int node){
	if(l == r) {
		scanf("%d",&st[node]);
		return;	
	}
	int mid = (l+r)/2;
	build(l,mid,2*node);
	build(mid+1,r,2*node+1);
	st[node] = st[2*node]+st[2*node+1];
}

int query(int ql,int qr,int l,int r,int node){
	if(ql <= l && qr >= r) return st[node];
	int mid = (l+r)/2;
	int sum = 0;
	if(ql <= mid) sum += query(ql,qr,l,mid,2*node);
	if(qr  > mid) sum += query(ql,qr,mid+1,r,2*node+1);
	return sum;
}

void update(int pos,int val,int l,int r,int node){
	if(l == r){
		st[node] += val;
		return;
	}
	int mid = (l+r)/2;
	if(pos < mid) update(pos,val,l,mid,2*node);
	else update(pos,val,mid+1,r,2*node+1);
	st[node] = st[2*node] + st[2*node+1];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		printf("Case %d:\n",c);
		int n;
		scanf("%d",&n);
		build(1,n,1);
		string s;
		while(cin>>s){
			if(s == "End") break;
			if(s == "Add"){
				int i,j;
				scanf("%d%d",&i,&j);
				update(i,j,1,n,1);
			}
			if(s == "Sub"){
				int i,j;
				scanf("%d%d",&i,&j);
				update(i,-j,1,n,1);
			}
			if(s == "Query"){
				int i,j;
				cin>>i>>j;
				printf("%d\n",query(i,j,1,n,1));
			}
		}
	}
}

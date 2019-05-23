#include<iostream>
using namespace std;
const int maxn = 1e4+5;
int p[maxn];

int find(int x){
	return x == p[x] ? x : find(p[x]);
}

void united(int x,int y){
		x = find(x); 
		y = find(y);
    p[x] = y;   
}

int main(){
	int n,m,q;
	while(cin>>n>>m>>q){
			for(int i=1;i<=n;i++)
				  p[i] = i;
		  while(m--){
		  	int a,b;
		  	cin>>a>>b;
		  	united(a,b);
			}
			while(q--){
				int a,b;
				cin>>a>>b;
				if(find(a) == find(b))
		 			cout<<":)"<<endl;	
		 		else cout<<":("<<endl;
		 }
	}
	
}

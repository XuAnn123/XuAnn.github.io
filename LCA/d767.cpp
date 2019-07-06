#include<bits/stdc++.h>
using namespace std;
const int maxn_v = 3e4+5;
int V,q,root = 1;
vector<int> G[maxn_v];
int p[20][maxn_v],d[maxn_v],max_log_v,dis[25];//log2 30000 = 14.xxx
int distance;
//p[x][v] v往上2的X次方所到達的點 

void build_distance(){
	dis[0] = 1;
	for(int i=1;i<25;i++)
		dis[i] = dis[i-1]<<1;//<<1(*2) >>1(/2)
}

void dfs(int pos,int parent,int depth){
	p[0][pos] = parent;
	d[pos] = depth;
	for(int i=0;i<G[pos].size();i++)
		dfs(G[pos][i],pos,depth+1);
}

void init(){
	//初始化p[0] 和 depth 
	dfs(root,-1,0);
	//將parent初始化 
	for(int i=0;i<max_log_v;i++)
		for(int v=1;v<=V;v++){
			if(p[i][v] == -1) p[i+1][v] = -1; 
			else p[i+1][v] = p[i][p[i][v]];
		}
}

int lca(int u,int v){
	//先往上到同深度 (不能跳到-1)
	if(d[u] > d[v]) swap(u,v);//v較u深 
	for(int i=max_log_v;i>=0;i--){
		if(p[i][v] != -1 && d[p[i][v]] >= d[u]){
		 v = p[i][v];
		 distance += dis[i];
		}
	}
	//cout<<"de "<<u<<" "<<v<<endl;
	if(u == v) return u;
	//二分搜求LCA  
	for(int k=max_log_v;k>=0;k--)
		if(p[k][u] != p[k][v]){
			u = p[k][u];
			v = p[k][v];
			distance += dis[k]<<1;//兩個一起往上->乘以2 
		}
	distance += 2;
	return p[0][u];
}

int main(){
	cin>>V>>q;
	max_log_v = log2(V);
	build_distance();
	for(int i=1;i<=V;i++){
		int a;
		while(cin>>a && a != 0)
			G[i].push_back(a);
	}
	init();
	//cout<<"p1"<<p[0][1]<<endl;
	//cout<<p[0][7]<<"de"<<p[1][7]<<"de"<<p[2][7]<<endl;
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = lca(a,b);
		distance = 0;
		cout<<ans<<" "<<distance<<endl;
	}
}

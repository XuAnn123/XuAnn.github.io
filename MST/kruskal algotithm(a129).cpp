#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int visit[maxn],p[maxn];

struct edge{
	int st,ed,cost;
	//連結cost的兩條邊 
}G[maxn];

bool cmp(edge a, edge b){
	return a.cost<b.cost;
}

int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		memset(visit,0,sizeof(visit));
		long long ans = 0;
		for(int i=0;i<n;i++)
			p[i] = i;
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&G[i].st,&G[i].ed,&G[i].cost);
		sort(G,G+m,cmp);
		for(int i=0;i<m;i++){
			int fst = find(G[i].st),fed = find(G[i].ed);
			if(fst != fed){
				p[fst] = fed;
				ans += G[i].cost;
			}
		}
		for(int i=0;i<n;i++)
			if(find(i) != find(0)){
				ans = -1;
				break;
			}
		printf("%lld\n",ans);
	}
}

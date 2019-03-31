#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,fx,fy,t,sum;
int visit[15][15];//1為可走 0障礙物
int dx[4] = {-1,0, 0,1};
int dy[4] = { 0,1,-1,0};

void dfs(int x,int y){
	if(x == fx && y == fy) {sum++; return;}
	else {
	    visit[x][y] = 0;
		for(int i=0;i<4;i++)
			if(visit[x+dx[i]][y+dy[i]] == 1){
				dfs(x+dx[i],y+dy[i]);
				visit[x+dx[i]][y+dy[i]] = 1;
			}			
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	cin>>n>>m>>t;
	sum = 0;
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			visit[i][j] = 1;
	cin>>sx>>sy>>fx>>fy;
	
	for(int i=0;i<t;i++){
		int xxx,yyy;
		cin>>xxx>>yyy;
		visit[xxx][yyy] = 0;
	}
	/*
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++)
			cout<<visit[i][j]<<" ";
		cout<<endl;	
	}*/
	
	dfs(sx,sy);
	cout<<sum<<endl;
	return 0;
}

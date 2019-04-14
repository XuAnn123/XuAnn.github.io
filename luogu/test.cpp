#include<iostream>
#include<queue>
using namespace std;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	int arr[1005][100005];
	int dx[4] = {0, 0,-1,1};
	int dy[4] = {1,-1,0 ,0};
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
			
	while(m--){
		queue < pair<int,int> > q;
		int ans = 1;
		int a,b;
		cin>>a>>b;
		q.push({a,b});
		while(q.size()){
			pair<int,int> now = q.front();
			int x = now.first, y = now.second;
			q.pop();
			for(int i=0;i<4;i++)
				if(arr[x+dx[i]][y+dy[i]] != arr[x][y]){
					ans++;
					arr[x+dx[i]][y+dy[i]] = arr[x][y];
					q.push({x+dx[i],y+dy[i]});
				}
		}
		cout<<ans<<'\n';
	}
	return 0; 
}

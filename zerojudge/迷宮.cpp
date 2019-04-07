#include<iostream>
#include<queue> 
#include<cstring>
using namespace std;
struct node{
int x,y;
};
int main(){
char arr[105][105];
int step[105][105];
int x[4]={1,-1, 0,0};
int y[4]={0, 0,-1,1};
int n;
while(cin>>n){
	memset(step,0,sizeof(step));
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	step[2][2] = 1;
	queue <node> q;
	q.push((node){2,2});
	while(!q.empty()){
		node temp = q.front();
		int xx = temp.x, yy = temp.y;
		q.pop();
		for(int i=0;i<4;i++){
			if(arr[xx+x[i]][yy+y[i]] == '.'){
				step[xx+x[i]][yy+y[i]] = step[xx][yy] + 1;
				q.push( (node) {(xx+x[i]),(yy+y[i])});
				arr[xx+x[i]][yy+y[i]] = '#';	
			}
		}			
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<step[i][j]<<" ";
		cout<<endl;
	}*/
	if(step[n-1][n-1] == 0) cout<<"No solution!"<<endl;
	else cout<<step[n-1][n-1]<<endl;
}
return 0;		
}

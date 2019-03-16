#include<cstring> 
#include<iostream> 
#include<queue>
using namespace std;
int n,step[105][105];
char arr[105][105];
//BFS
struct node{
int x,y;
};

int main(){
int dx[4] = {1,-1,0,0} , dy[4] = {0,0,1,-1};
//x[0]y[0] 下降一格 x[1]y[1] 上升一格 x[2]y[2] 往右一格 x[3]y[3] 往左一格
queue<node> q;
memset(step,0,sizeof(step));
cin>>n;	
for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		cin>>arr[i][j];	
		if(arr[i][j]=='#')	step[i][j] = 0;
	}

step[2][2]=1;
q.push( (node){2,2} );

while(!q.empty()){
	for(int k=0;k<4;k++){ //控制上下左右 
		node temp = q.front();
		int xx = temp.x , yy = temp.y;  	
		q.pop();
		if(arr[xx][yy] == '.') {	
			step[xx][yy] = step[xx+dx[k]][xx+dx[k]] + 1;
			q.push( (node){xx+dx[k],xx+dy[k]} );
			arr[xx+dx[k]][xx+dx[k]] = '#';
		}
		}
}	

for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++)
		cout<<step[i][j]<<" ";
	cout<<endl;
}
		
return 0;
}

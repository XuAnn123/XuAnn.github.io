#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,_ma,temp = 0;
int num[25];
bool used[25];
vector <int> v;
bool flag = true;

void dfs(int pos,int start){
	if (pos == _ma) {
		flag = false;
		for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
		cout<<endl;
		return;
	}
	for(int i=start;i<=n;i++){
		if(used[i] == 0 && pos+num[i]<=_ma){
			temp += num[i];	
			used[i] = 1;
			v.push_back(num[i]);
			dfs(temp,i+1);
			//tracing back
			used[i] = 0;
			temp-= num[i];
			v.pop_back();
		}
	}
}

int main(){
	memset(used,0,sizeof(used));
	cin>>n>>_ma;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	dfs(0,1);
	if(flag) cout<<"NO"<<endl;
	return 0;
}

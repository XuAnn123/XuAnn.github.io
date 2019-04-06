#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> v;

void dfs(int pos,int start){
	//cout<<pos<<" "<<start<<endl;
	if(pos == m){
		for(int i=0;i<v.size();i++) cout<<v[i];
		cout<<endl;
		return;
	}
	else{
		for(int i=start;i<=n;i++){
			v.push_back(i);
			dfs(pos+1,i+1);
			v.pop_back();//tracing back
		}
	}
}

int main(){
	cin>>n>>m;
	dfs(0,1);
	return 0;
}

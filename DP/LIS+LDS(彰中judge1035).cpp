#include<bits/stdc++.h> 
using namespace std;
int num[505];
int lis[505];
int lds[505];
int n;
//可重複
void clis(){
	//以i為開頭的LIS 
	for(int i=n;i>=1;i--)
		for(int j=n;j>i;j--)
			if(num[j] >= num[i]) 
				lis[i] = max(lis[i],lis[j]+1);
}

void clds(){
	//以i為開頭的LDS
	for(int i=n;i>=1;i--)
		for(int j=n;j>i;j--)
			if(num[j] <= num[i])
				lds[i] = max(lds[i],lds[j]+1);
}

int main(){
	while(cin>>n && n){
		memset(lis,0,sizeof(lis));
		memset(lds,0,sizeof(lds));
		int i,j;
		int ans = 0;
		for(i=1;i<=n;i++){
			cin>>num[i];
			lis[i] = 1;
			lds[i] = 1;
		}
		clis();
		clds();
		/*for(i=1;i<=n;i++)
			cout<<lis[i]<<" ";
		cout<<endl;
		for(i=1;i<=n;i++)
			cout<<lds[i]<<" ";*/
		for(i=1;i<=n;i++){
			ans = max(lis[i],ans);
			ans = max(lds[i],ans);
			for(j=i+1;j<=n;j++){
				if(num[j] > num[i]) ans = max(ans,lis[j]+lds[i]);
				else if(num[j] < num[i]) ans = max(ans,lds[j]+lis[i]);
			}
		}
		cout<<ans<<endl;
	}
}

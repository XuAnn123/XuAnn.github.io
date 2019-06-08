#include<bits/stdc++.h> 
using namespace std;
int n,num[2005],lis[2005],lds[2005];

void LIS(){
	//以i為開頭的lis 
	for(int i=n;i>=1;i--)
		for(int j=n;j>i;j--)
			if(num[j] > num[i]) lis[i] = max(lis[i],lis[j]+1);
}

void LDS(){
	//以i為開頭的lds 
	for(int i=n;i>=1;i--)
		for(int j=n;j>i;j--)
			if(num[j] < num[i]) lds[i] = max(lds[i],lds[j]+1);
}

int main(){
	int N;
	cin>>N;
	while(N--){
		int ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			lis[i] = 1;
			lds[i] = 1;
		}	
		LIS();
		LDS();
		for(int i=1;i<=n;i++){
			ans = max(ans,max(lis[i],lds[i]));
			for(int j=i+1;j<=n;j++){
				if(num[j]>num[i])
					ans = max(ans,lis[j]+lds[i]);
				else if(num[j]<num[i])
					ans = max(ans,lis[i]+lds[j]);
			}
		}
		cout<<ans<<endl;
	}
}

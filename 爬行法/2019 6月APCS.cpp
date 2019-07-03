#include<bits/stdc++.h>
using namespace std;
//給一段長度為m的彩帶，最多有n種顏色
//求長度為m的這條彩帶內共有幾條長度為n且有n種顏色的「完美彩帶」 
const int maxn = 1e5+5;
int a[maxn];
int main(){
	int n,m,ans = 0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);	
	int s = 0,t = 0,num = 0;
	map<int,int> count;
	while(true){
		while(t < m && num < n){
			if(count[a[t]] == 0){
				num++;
				count[a[t]]++;
			}
			t++;
		}
		if(num < n) break;
		ans++;
		count[a[s]]--;
		if(count[a[s]] == 0)
			num--;
		s++;	
	}
	cout<<ans<<endl;
}

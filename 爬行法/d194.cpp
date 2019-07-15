#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 1e6+5;
string a[maxn];
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	int N;
	cin>>N;
	while(N--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		deque<string> dq;
		unordered_set<string> s;
		int ans = -1;
		for(int i=1;i<=n;i++){
			if(s.find(a[i]) == s.end()){
				s.insert(a[i]);
				dq.pb(a[i]);
			}
			else{
				while(dq.front() != a[i]){
					string remov = dq.front();
					s.erase(remov);
					dq.pop_front();
				}
				dq.pop_front();
				dq.pb(a[i]);
			}
			int sz = dq.size();
			ans = max(ans,sz);
		}
		cout<<ans<<endl;
	} 
}

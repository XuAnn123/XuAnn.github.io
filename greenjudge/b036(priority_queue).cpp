#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n,i,k;
	priority_queue <int,vector<int>,greater<int> > pq;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		pq.push(k);
	}
	int sum = 0;
	while(pq.size() >= 2){
		int k = 0;
		for(int j=0;j<2;j++){
			k += pq.top();
			pq.pop();
		}
		pq.push(k);
		sum += k;
	}
	cout<<sum<<endl;
	return 0;	
}

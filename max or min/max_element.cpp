#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	vector<int> v;
	for(int i=1;i<=10;i++)
		v.push_back(i);
	cout<<*max_element(a,a+10)<<endl;
	cout<<*min_element(a,a+10)<<endl;
	cout<<*max_element(v.begin(),v.end())<<endl;
	cout<<*min_element(v.begin(),v.end())<<endl;
}

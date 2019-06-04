#include<bits/stdc++.h> 
using namespace std;
long long sum = 0;

int check(string s){
		for(int j=1;j<=5;j++){
			for(int k=2;k<=4;k++){
			string st = v[k];	
			bool flag = 1;
			for(int i=j;i<8;i++)
				if(st[i] != s[i]){
					flag = 0;
					break;
				}	
			if(flag)
				return 8-j;
		}
	}
	return 0;
}

void check3(string s){
	for(int i=5;i<v.size();i++){
		string st  = v[i];
		bool flag = 1;
		for(int j=5;j<8;j++)
			if(st[j] != s[j]){
				flag = 0;
				break;
			}
		if(flag) sum += 200;
	}
}

int main(){
	v.clear();
	sum = 0;
	for(int i=0;i<5;i++){
		string st;
		cin>>st;
		v.push_back(st);
	}
	
	string s;
	while(cin>>s&&s.size()<=3)
		v.push_back(s);
	
	while(cin>>s && s!="0"){
		if(s == v[0])
			sum += 10000000;
		else if(s == v[1])
			sum += 2000000;	
		else if(s == v[2]||s == v[3]||s == v[4])
			sum += 200000;	
		else if(check(s) != 0){
			int temp = check(s);
			if(temp  == 7)
				sum += 40000;	
			if(temp== 6)
				sum += 10000;	
			if(temp  == 5)
				sum += 4000;	
			if(temp == 4)
				sum += 1000;	
			if(temp== 3)
				sum += 200;
		}
		check3(s);
	}

	cout<<sum<<endl;
}

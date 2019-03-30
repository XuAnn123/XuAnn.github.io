#include<iostream>
using namespace std;
int total,_max = 0;

struct word{
string str;
int len = 0;
int left = 2;
}words[25];

int judge(string a,string b){
int lena = a.size();
int lenb = b.size();
for(int i=1;i<lena&&i<lenb;i++){
		bool flag = true;
		for(int j=0;j<i;j++)
			if(a[lena-i+j] != b[j]) 
				{flag = false;	break;}
			if(flag) return i;
}
return 0;
}

void dfs(string s,int num){
		_max = max(_max,num);
		int a;
		for(int i=0;i<total;i++)
				if(words[i].left > 0){
						a = judge(s,words[i].str);
						if(a>0){
							words[i].left--;		
							dfs(words[i].str,words[i].len+num-a);
							words[i].left++;
						}
				}
}

int main(){
cin>>total;	
for(int i=0;i<total;i++){
		cin>>words[i].str;
		words[i].len = (words[i].str).size();
}
char st;
cin>>st;
for(int i=0;i<total;i++){
		if(words[i].str[0] == st){
			words[i].left--;
			dfs(words[i].str,words[i].len);
			words[i].left++;
		}		
}		
cout<<_max<<endl;	
}

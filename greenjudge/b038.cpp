#include<iostream>  
#include<vector>  
#include<cstring>  
using namespace std;  
int visit[10];  
int n;  
vector <int> v;  
  
void dfs(int pos){  
//pos紀錄長度   
if(pos == n){  
    for(int i=0;i<v.size();i++)  
        cout<<v[i];  
    cout<<endl;  
    return;  
}  
else   
    for(int i=1;i<=n;i++){  
        if(visit[i] == 0){  
            v.push_back(i);  
            visit[i] = 1;  
            dfs(pos+1);  
            //tracing back  
            v.pop_back();  
            visit[i] = 0;  
        }  
    }   
}  
  
int main(){  
memset(visit,0,sizeof(visit));  
cin>>n;  
dfs(0);  
return 0;  
}  

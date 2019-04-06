#include<iostream>  
#include<vector>  
using namespace std;  
int num[10],n,m;  
vector<int> v;  
//可重複，不用用visit紀錄   
void dfs(int now){  
    if(now == n){//長度為n   
        for(int i=0;i<v.size();i++)  
            cout<<v[i];  
        cout<<endl;  
        return;  
    }  
    else {  
        for(int i=0;i<=m;i++){  
            v.push_back(num[i]);  
            dfs(now+1);//下一層   
            v.pop_back();//回溯     
        }  
    }  
}  
  
int main(){  
    cin>>n>>m;  
    for(int i=0;i<=m;i++) num[i] = i;  
    dfs(0);  
    return 0;  
}   

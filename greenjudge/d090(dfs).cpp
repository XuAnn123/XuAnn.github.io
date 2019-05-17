#include<iostream>  
#include<cstring>  
#include<vector>  
#include<list>  
#include<algorithm>  
using namespace std;  
int map[4][12];//visit  
int n,cnt = 0,temp;  
vector <int> v[1000];//  
int dx[8]={-1, -2 , 1 , 2 ,-2 ,-1 ,2 ,1};  
int dy[8]={-2, -1 ,-2 ,-1 , 1 , 2, 1 ,2};  
  
void record(){  
    for(int i=1;i<=3;i++)  
        for(int j=1;j<=n;j++)  
            v[cnt].push_back(map[i][j]);  
    cnt++;  
}  
  
void dfs(int x,int y,int num){  
    if(map[x][y]!=0||(x>3)||(y>n)||(x<1)||(y<1)) return;  
    map[x][y] = num;  
    if(num == 3*n)  
        record();  
    for(int i=0;i<8;i++)  
        dfs(x+dx[i],y+dy[i],num+1);  
    map[x][y] = 0;//tracing back  
}  
  
int main(){  
    while(cin>>n){  
        memset(map,0,sizeof(map));  
        cnt = 0;  
        for(int i=0;i<1000;i++)  
            v[i].clear();  
        dfs(1,1,1);  
        //cout<<cnt<<endl;  
        /*for(int i=1;i<=3;i++){ 
            for(int j=1;j<=n;j++) 
                cout<<map[i][j]<<" "; 
            cout<<'\n'; 
        }*/  
        if(v[0].empty()) cout<<"0"<<endl;  
        else{  
            int si = v[0].size();  
            for(int i=0;i<si;i++){  
                int _min = 1e5;  
                for(int k=0;k<cnt;k++)  
                    if(v[k].size())  
                        _min = min(_min,v[k][i]);  
      
                for(int j=0;j<cnt;j++)  
                    if(v[j][i] != _min)  
                        v[j].clear();  
            }  
            for(int i=0;i<cnt;i++)  
                if(v[i].size()){  
                    for(int j=0;j<v[i].size();j++)  
                        cout<<v[i][j]<<" ";  
                }  
            /*for(int i=0;i<v[vec[0]].size();i++) 
                cout<<v[vec[0]][i]<<" ";*/  
        }  
    }  
}  

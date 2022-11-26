#include<bits/stdc++.h>
using namespace std;

int m,n;
int G[101][101];
bool visited[101][101];
int day=0;
int dx[]={-1, 0, 1, 0};
int dy[]={ 0, 1, 0,-1};
bool chk=false;
queue<pair<int,int> > q;

bool is_valid(int curr_x, int curr_y){
    if(curr_x<0 || curr_y<0 || curr_x>=m || curr_y>=n) return false;
    if(G[curr_x][curr_y]==1) return true;
    return false;
}

void solve(){
    while(!q.empty()){
        pair<int,int> tmp;
        day++;
        int lv = q.size();
        while(lv--){
            tmp = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                if(is_valid(tmp.first + dx[i],tmp.second + dy[i])){
                    G[tmp.first + dx[i]][tmp.second + dy[i]] = 2;
                    visited[tmp.first + dx[i]][tmp.second + dy[i]]=true;
                    q.push({tmp.first + dx[i],tmp.second + dy[i]});
                }
            }
        }
    }
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(G[i][j]==1)
                    chk=true;
            }
    }
        if(chk) cout<<"-1\n";
        else
            cout<<day-1<<"\n";
}
main(){
    int T;
    cin >>T;
    while(T--){
        day =0;
        chk=false;
        cin>>m>>n;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >>G[i][j];
                
                if(G[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        solve();
    }
}

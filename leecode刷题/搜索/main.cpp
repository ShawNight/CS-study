#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void BFS(vector<vector<char>> &grid,vector<vector<int>> &visit,int x,int y){
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visit[x][y]=1;
    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX<0||newX>=visit.size()||newY<0||newY>=visit[newX].size()){
                continue;
            }
            if(visit[newX][newY]==0 &&grid[newX][newY]=='1')
            {
                Q.push(make_pair(newX,newY));
                visit[newX][newY]=1;
            }
        }
    }

}

int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visit(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'&&visit[i][j]==0){
                BFS(grid,visit,i,j);
                result++;
            }
        }
    }
    return result;
    
}


int main(){
    vector<vector<char>> grid={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout<<numIslands(grid)<<endl;
    return 0;
}
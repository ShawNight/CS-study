#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(vector<vector<int>> &mark,vector<vector<char>> grid,int x,int y){
    mark[x][y]=1;
    static const int dx[]={-1,1,0,0};
    static const int dy[]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int newX=x+dx[i];
        int newY=y+dy[i];
        if(newX<0||newX>=mark.size()||newY<0||newY>=mark[newX].size()){
            continue;
        }
        if(mark[newX][newY] == 0 && grid[newX][newY]=='1'){
            DFS(mark,grid,newX,newY);
        }
    }
}

void BFS(vector<vector<int>> &mark,vector<vector<char>> &grid,int x,int y){
    static const int dx[]={-1,1,0,0};
    static const int dy[]={0,0,-1,1};
    queue<pair<int,int>> Q;
    Q.push({x,y});
    mark[x][y]=1;
    while(!Q.empty()){
        pair<int,int> node=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int newX=node.first+dx[i];
            int newY=node.second+dy[i];
            if(newX<0||newX>=mark.size()||newY<0||newY>=mark[newX].size()){
                continue;
            }
            if(mark[newX][newY] == 0 && grid[newX][newY]=='1'){
                Q.push({newX,newY});
                mark[newX][newY]=1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int island_num=0;
    vector<vector<int>> mark;
    for(int i=0;i<grid.size();i++){
        mark.push_back(vector<int>(grid[i].size(),0));
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(mark[i][j]==0&&grid[i][j]=='1'){
                BFS(mark,grid,i,j);
                island_num++;
            }
        }
    }
    return island_num;
}
int main(){
    vector<vector<char>> grid={
         {'1','1','0','0','0'},
         {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout<<numIslands(grid)<<endl;
    return 0;
}
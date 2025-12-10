#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct QItem{
    int x;
    int y;
    int h;
    QItem(int x,int y,int h):x(x),y(y),h(h){}
};
struct cmp{
    bool operator()(const QItem &l,const QItem &r){
        return l.h>r.h;
    }
};
int trapRainWater(vector<vector<int>>& heightMap) {
    priority_queue<QItem,vector<QItem>,cmp> Q;
    if(heightMap.size()<3 || heightMap[0].size()<3){
        return 0;
    }
    int row=heightMap.size();
    int column=heightMap[0].size();
    vector<vector<int>> mark;
    for(int i=0;i<row;i++){
        mark.push_back(vector<int>());
        for(int j=0;j<column;j++){
            mark[i].push_back(0);
        }
    }
    for(int i=0;i<row;i++){
        Q.push(QItem(i,0,heightMap[i][0]));
        mark[i][0]=1;
        Q.push(QItem(i,column-1,heightMap[i][column-1]));
        mark[i][column-1]=1;
    }
    for(int i=0;i<column;i++){
        Q.push(QItem(0,i,heightMap[0][i]));
        mark[0][i]=1;
        Q.push(QItem(row-1,i,heightMap[row-1][i]));
        mark[row-1][i]=1;
    }
    static const int dx[]={-1,1,0,0};
    static const int dy[]={0,0,-1,1};
    int result=0;  //最终积水量
    while(!Q.empty()){
        int x=Q.top().x;
        int y=Q.top().y;
        int h=Q.top().h;
        Q.pop();
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX<0||newX>=row||newY<0||newY>=column||mark[newX][newY])
                continue;
            if(h>heightMap[newX][newY]){
                result+=h-heightMap[newX][newY];
                heightMap[newX][newY]=h;
            }
            Q.push(QItem(newX,newY,heightMap[newX][newY]));
            mark[newX][newY]=1;

        }
    }
    return result;
}
int main(){
    
    return 0;
}
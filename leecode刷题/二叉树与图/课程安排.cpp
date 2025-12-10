#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

bool DFS_graph(int i,vector<vector<int>> &graph,vector<int>& visit){
    visit[i]=1;
    for(int k=0;k<graph[i].size();k++){
        if(visit[graph[i][k]]==0){
            if(!DFS_graph(graph[i][k],graph,visit)){
                return false;
            }
        }else if(visit[graph[i][k]]==1){
            return false;
        }
    }
    visit[i]=2;
    return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses,vector<int>());
    vector<int> visit(numCourses,0);
    for(int i=0;i<prerequisites.size();i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for(int i=0;i<graph.size();i++){
        if(visit[i]==0&&!DFS_graph(i,graph,visit)){
            return false;
        }
    }
    return true;
    
}
int main(){
    vector<vector<int>> prerequisites={{0,1},{1,0}};
    cout<<canFinish(2,prerequisites)<<endl;
    return 0;
}
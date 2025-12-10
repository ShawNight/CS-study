#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses,vector<int>()); //图
    vector<int> degree(numCourses,0);   //入度数组
    for(int i=0;i<prerequisites.size();i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        degree[prerequisites[i][1]]++;
    }
    queue<int> Q;
    for(int i=0;i<degree.size();i++){
        if(degree[i]==0)
            Q.push(i);
    }
    int count=0;
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        count++;
        for(int i=0;i<graph[node].size();i++){
            degree[graph[node][i]]--;
            if(degree[graph[node][i]]==0)
                Q.push(graph[node][i]);
        }
    }
    return count==numCourses; 
}
int main(){
    vector<vector<int>> prerequisites={{0,1},{1,2}};
    cout<<canFinish(3,prerequisites)<<endl;
    return 0;
}
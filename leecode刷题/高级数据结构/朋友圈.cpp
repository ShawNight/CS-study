#include<iostream>
#include<vector>
using namespace std;
void DFS_graph(int u,vector<vector<int>>& graph,vector<int>& visit){
    visit[u]=1;
    for(int i=0;i< graph[u].size();i++)
    {
        if(visit[i] == 0 && graph[u][i] == 1){
            DFS_graph(i,graph,visit);
        }
    }
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visit(M.size(),0);
        int count=0;
        for(int i=0;i<M.size();i++){
            if(visit[i]==0){
                DFS_graph(i,M,visit);
                count++;
            }
        }
        return count;
    }
};
int main()
{
    vector<vector<int>> M={{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    cout<<s.findCircleNum(M)<<endl;
    return 0;
}
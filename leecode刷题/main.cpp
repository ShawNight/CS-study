#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>
using namespace std;
struct TreeNode{
    int val;    //数据域
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void generate(TreeNode *node,vector<vector<int>> &results,vector<int> &temp,int sum,int targetSum){
    temp.push_back(node->val);
    sum += node->val;
    if(node->left)
        generate(node->left,results,temp,sum,targetSum);
    if(node->right)
        generate(node->right,results,temp,sum,targetSum);
    if(!node->left && !node->right && sum ==targetSum)
        results.push_back(temp);
    temp.pop_back();
    sum -= node->val;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> results;
    vector<int> temp;
    generate(root,results,temp,0,targetSum);
    return results;

}

void preorder(TreeNode *node,TreeNode *search,vector<TreeNode*> &path,vector<TreeNode*> &result,int finish){
    if(!node||finish == 1)
        return;
    path.push_back(node);
    if(node == search){
        finish = 1;
        result = path;
    }
    preorder(node->left,search,path,result,finish);
    preorder(node->right,search,path,result,finish);
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path;
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;
    int finish = 0;
    preorder(root,p,path,p_path,finish);
    path.clear();
    preorder(root,q,path,q_path,finish);
    int path_len;
    if(p_path.size()<q_path.size())
        path_len = p_path.size();
    else
        path_len = q_path.size();
    TreeNode* result=NULL;
    for(int i=0; i<path_len;i++){
        if(p_path[i] = q_path[i])
        {
            result = p_path[i];
        }
    }
    return result;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses,0);
    for(int i = 0; i<prerequisites.size();i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }
    queue<int> Q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)
            Q.push(i);
    }
    while(!Q.empty()){
        int num = Q.front();
        Q.pop();
        numCourses--;
        for(int i=0;i<graph[num].size();i++){
            indegree[graph[num][i]]--;
            if(indegree[graph[num][i]] == 0)
                Q.push(graph[num][i]);
        }
    }
    return 0 == numCourses;
    
}
int main(){
    vector<vector<int>> prerequisites={{1,2},{1,0},{2,0}};
    cout<<canFinish(3,prerequisites);
    return 0;
}
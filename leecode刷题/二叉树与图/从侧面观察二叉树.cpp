#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) {
    queue<pair<TreeNode*,int>> Q;
    vector<int> result;
    Q.push(make_pair(root,0));
    while(!Q.empty()){
        TreeNode* node=Q.front().first;
        int depth=Q.front().second;
        if(depth==result.size()){
            result.push_back(node->val);
        }else{
            result[depth]=node->val;
        }
        Q.pop();
        if(node->left){
            Q.push(make_pair(node->left,depth+1));
        }
        if(node->right){
            Q.push(make_pair(node->right,depth+1));
        }
    }
    return result;
    
}
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left= &b;
    a.right=&c;
    b.left=&d;
    b.right=&e;
    c.right=&f;
    vector<int> result;
    result=rightSideView(&a);
    for(auto val:result)
        cout<<val<<" ";
    return 0;
}
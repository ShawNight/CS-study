#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 int main(){
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
    queue<TreeNode*> Q;
    Q.push(&a);
    while(!Q.empty()){
        TreeNode* temp=Q.front();
        Q.pop();
        cout<<temp->val<<" ";
        if(temp->left){
            Q.push(temp->left);
        }
        if(temp->right){
            Q.push(temp->right);
        }
    }
    return 0;
 }
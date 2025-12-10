#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    void preorder(TreeNode *node,TreeNode *&last){
        if(!node){
            return;
        }
        if(!node->left&&!node->right){
            last=node;
            return;
        }
        TreeNode *left=node->left;
        TreeNode *right=node->right;
        TreeNode *left_last=NULL;
        TreeNode *right_last=NULL;
        if(left){
            preorder(left,left_last);
            node->left=NULL;
            node->right=left;
            last=left_last;
        }
        if(right){
            preorder(right,right_last);
            if(left_last){
                left_last->right=right;
            }
            last=right_last;
        }
    }
    void flatten(TreeNode* root) {
        TreeNode *last=NULL;
        preorder(root,last);
    }
};
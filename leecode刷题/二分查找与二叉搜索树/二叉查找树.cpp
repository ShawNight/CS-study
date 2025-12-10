#include<iostream>
using namespace std;
struct TreeNode{
    int val;    //数据域
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void BST_insert(TreeNode* node,TreeNode *insert_node){
    if(insert_node->val<node->val){
       if(node->left){
           BST_insert(node->left,insert_node);
       }else{
           node->left=insert_node;
       }
    }else{
        if(node->right){
            BST_insert(node->right,insert_node);
        }else{
            node->right=insert_node;
        }
    }
}
bool BST_search(TreeNode *node,int value){
    if(node->val==value)
        return true;
    if(value<node->val){
        if(node->left){
            BST_search(node->left,value);
        }else{
            return false;
        }

    }
    if(value>node->val){
        if(node->right){
            BST_search(node->right,value);
        }else{
            return false;
        }
    }
}
int main(){
    

    return 0;
}
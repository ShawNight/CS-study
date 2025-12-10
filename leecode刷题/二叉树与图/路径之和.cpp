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
    void generate(int sum,int targetSum,vector<int>& temp,vector<vector<int>>&result,TreeNode* node){
        if(!node)
            return;
        temp.push_back(node->val);
        sum+=node->val;
        if(!node->left&&!node->right&&sum==targetSum)
        {
            result.push_back(temp);
            sum-=node->val;
            temp.pop_back();
            return;
        }
        generate(sum,targetSum,temp,result,node->left);
        generate(sum,targetSum,temp,result,node->right);
        sum-=node->val;
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum=0;
        generate(sum,targetSum,temp,result,root);
        return result;
    }
};
int main()
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode h(7);
    TreeNode i(2);
    TreeNode j(5);
    TreeNode k(1);
    a.left=&b;
    a.right=&c;
    b.left=&d;
    c.left=&e;
    c.right=&f;
    d.left=&h;
    d.right=&i;
    f.left=&j;
    f.right=&k;
    vector<vector<int>> result;
    Solution s;
    result=s.pathSum(&a,22);
    for(auto r:result){
        for(auto n:r){
            cout<<n<<" ";
        }
        cout<<endl;
    }

    return 0;
}
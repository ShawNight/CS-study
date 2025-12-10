#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;

//递归二分查找
bool binary_search_1(vector<int> &sort_array,int begin,int end,int target){
    if(begin>=end){
        return false;
    }
    int mid = (begin+end)/2;
    if(target == sort_array[mid]){
        return true;
    }
    else if(target < sort_array[mid]){
        binary_search_1(sort_array,begin,mid-1,target);
    }else{
        binary_search_1(sort_array,mid+1,end,target);
    }
}

//循环二分查找
bool binary_search_2(vector<int> &sort_array,int target){
    int begin = 0;
    int end = sort_array.size()-1;
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == sort_array[mid])
            return true;
        else if(target < sort_array[mid]){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    return false;
}
int searchInsert(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size()-1;
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid]){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    int num = begin<end?begin:end;
    return num+1;
}
vector<int> searchRange_1(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size()-1;
    vector<int> result={-1,-1};
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid]){
            result[0]=result[1]=mid;
            int left = mid;
            while(left>=0&&nums[left] == target) left--;
            result[0] = left+1;
            int right = mid;
            while(right< nums.size() &&nums[right] == target) right++;
            result[1] = right -1;
            break;
        }
        else if(target < nums[mid]){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    return result;
}
vector<int> searchRange_2(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size()-1;
    vector<int> result={-1,-1};
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid]){
            if(mid == nums.size()-1 || nums[mid+1]>target){
                result[1] = mid;
            }
            begin = mid+1;
        }
        else if(target < nums[mid]){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    begin = 0;
    end = nums.size()-1;
    while(begin<=end){
        int mid = (begin+end)/2;
        if(target == nums[mid]){
            if(mid == 0 || nums[mid-1]<target){
                result[0] = mid;
            }
            end = mid-1;
        }
        else if(target < nums[mid]){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    return result;
}
int search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size()-1;
    while(begin <= end){
        int mid = (begin+end)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target < nums[mid]){
            if(nums[begin] < nums[mid]){
                if(target >= nums[begin])
                {
                    end = mid -1;
                }else{
                    begin = mid+1;
                }
            }
            else if(nums[begin] > nums[mid]){
                end = mid -1;
            }
            else if(nums[begin] == nums[mid]){
                begin = mid+1;
            }
        }
        else if(target > nums[mid]){
            if(nums[begin] < nums[mid]){
                begin = mid+1;
            }
            else if (nums[begin] == nums[mid]){
                end = mid -1;
            }
            else if(nums[begin] > nums[mid]){
                if(target >= nums[begin]){
                    end = mid -1;
                }
                else{
                    begin = mid + 1;
                }
            }
        }
    }
    return -1;
        
}

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void BST_insert(TreeNode *node,TreeNode *insert_node){
    if(insert_node->val < node->val){
        if(node->left){
            BST_insert(node->left,insert_node);
        }else{
            node->left = insert_node;
        }
    }
    else{
        if(node->right){
            BST_insert(node->right,insert_node);
        }else{
            node->right = insert_node;
        }
    }
}
void preorder_order(TreeNode *node,int layer){
    if(!node){
        return;
    }
    for(int i = 0;i<layer;i++){
        printf("-----");
    }
    preorder_order(node->left,layer+1);
    printf("[%d]\n",node->val);
    preorder_order(node->right,layer+1);
}

bool BST_search(TreeNode *node,int value){
    if(node->val == value){
        return true;
    }
    else if(value < node->val){
        if(node->left){
            BST_search(node->left,value);
        }else{
            return false;
        }
    }
    else if(value >node->val){
        if(node->right){
            BST_search(node->right,value);
        }
        else{
            return false;
        }
    }
}
void change_int_string(int val,string &str_val){
    string tmp="";
    while(val){
        tmp+=val%10+'0';
        val = val/10;
    }for(int i =tmp.size()-1;i>=0;i--){
        str_val+=tmp[i];
    }
    str_val+='#';
}
void BST_preorder(TreeNode *node,string &data){
    if(!node){
        return;
    }
    string str_val;
    change_int_string(node->val,str_val);
    data +=str_val;
    BST_preorder(node->left,data);
    BST_preorder(node->right,data);
}
string serialize(TreeNode* root) {
    string data;
    BST_preorder(root,data);
    return data;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.length()==0){
        return NULL;
    }
    vector<TreeNode*> node_vec;
    int val=0;
    for(int i=0;i<data.size();i++){
        if(data[i] == '#'){
            node_vec.push_back(new TreeNode(val));
            val=0;
        }else{
            val = val*10+(data[i]-'0');
        }
    }
    for(int i=1;i<node_vec.size();i++){
        BST_insert(node_vec[0],node_vec[i]);
    }
    return node_vec[0];
}


int main(){

    return 0;
}
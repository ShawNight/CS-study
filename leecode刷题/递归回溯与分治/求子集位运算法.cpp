#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    int all_test=1<<nums.size();    //左移n位，相当于2^n
    for(int i=0;i<all_test;i++){
        vector<int> item;
        for(int j=0;j<nums.size();j++){
            if(i&(1<<j)){   //构造数字i代表的集合,各元素存储至item
                item.push_back(nums[j]);
            }
        }
        result.push_back(item);
    }
    return result;

}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> result;
    result=subsets(nums);
    for(auto vec:result){
        cout<<"[";
        for(auto n:vec){
            cout<<n<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
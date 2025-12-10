#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void findsubsets(int i,vector<int>& nums,vector<int> &temp,vector<vector<int>> &result,set<vector<int>> &res_set){
    if(i==nums.size())
    {
        if(res_set.find(temp)==res_set.end()){
            result.push_back(temp);
        }
        return;
    }
    temp.push_back(nums[i]);
    findsubsets(i+1,nums,temp,result,res_set);
    temp.pop_back();
    findsubsets(i+1,nums,temp,result,res_set);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> temp;
    set<vector<int>> res_set;
    sort(nums.begin(),nums.end());
    result.push_back(temp);
    findsubsets(0,nums,temp,result,res_set);
    return result;
}
int main(){
    vector<int> nums={1,2,4,2};
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
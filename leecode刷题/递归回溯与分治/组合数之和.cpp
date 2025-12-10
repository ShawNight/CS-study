#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void findsubsets(int i,vector<int>& nums,vector<int> temp,vector<vector<int>> &result,set<vector<int>> &res_set,int sum,int target){
    sum+=nums[i];
    if(i>=nums.size()||sum>target)
    {
        return;
    }
    temp.push_back(nums[i]);
    if(sum==target&&res_set.find(temp)==res_set.end()){
        cout<<sum<<endl;
        for(auto n:temp)
            cout<<n<<" ";
        cout<<endl;
        result.push_back(temp);
        res_set.insert(temp);
        return;
    }
    findsubsets(i+1,nums,temp,result,res_set,sum,target);
    temp.pop_back();
    sum-=nums[i];
    findsubsets(i+1,nums,temp,result,res_set,sum,target);
}

vector<vector<int>> subsets(vector<int>& nums,int target){
    vector<vector<int>> result;
    vector<int> temp;
    set<vector<int>> res_set;
    sort(nums.begin(),nums.end());
    int sum=0;
    findsubsets(0,nums,temp,result,res_set,sum,target);
    return result;
}
int main(){
    vector<int> nums={10,1,2,7,6,1,5};
    vector<vector<int>> result;
    result=subsets(nums,8);
    for(auto vec:result){
        cout<<"[";
        for(auto n:vec){
            cout<<n<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
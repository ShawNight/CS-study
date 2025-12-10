#include<iostream>
#include<vector>
using namespace std;

void findsubsets(int i,vector<int>& nums,vector<int> &temp,vector<vector<int>> &result){
    if(i==nums.size())
    {
        result.push_back(temp);
        return;
    }
    findsubsets(i+1,nums,temp,result);
    temp.push_back(nums[i]);
    findsubsets(i+1,nums,temp,result);
    temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> temp;
    findsubsets(0,nums,temp,result);
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
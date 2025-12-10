#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int i=0;
    int max=nums[0];
    while(max<nums.size()&&i<max){
        i++;
        if(max<i+nums[i])
            max=i+nums[i];
    }
    if(max<nums.size())
        return false;
    else
        return true;
}

int main(){
    vector<int> nums={3,2,1,0,4};
    cout<<canJump(nums)<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int len=nums.size();
    vector<int> f(len,0);
    int maxx=nums[0];
    f[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        f[i]=max(f[i-1]+nums[i],nums[i]);
        if(maxx<f[i])
            maxx=f[i];
    }
    return maxx;
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}
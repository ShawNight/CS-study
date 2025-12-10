#include<iostream>
#include<vector>
using namespace std;
// int lengthOfLIS(vector<int>& nums) {
//     vector<int> dp(nums.size(),0);
//     dp[0]=1;
//     int maxx=1;
//     for(int i=1;i<nums.size();i++){
//         dp[i]=1;
//         for(int j=i-1;j>=0;j--){
//             if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
//                 dp[i]=dp[j]+1;
//             }
//         }
//         if(maxx<dp[i])
//             maxx=dp[i];
//     }
//     return maxx;
// }
int lengthOfLIS(vector<int>& nums) {
    vector<int> S;
    S.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>S.back()){
            S.push_back(nums[i]);
        }else{
            for(int j=0;j<S.size();j++){
                if(S[j]>=nums[i]){
                    S[j]=nums[i];
                    break;
                }
            }
        }
    }
    return S.size();
}
int main(){
    vector<int> nums={4,10,4,3,8,9};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
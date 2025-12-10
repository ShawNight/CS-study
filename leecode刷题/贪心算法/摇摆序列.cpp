#include<iostream>
#include<vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int len=nums.size();
    if(len<2) return len;
    int count=1;
    for(int i=1;i<len;i++){
        if(nums[i-1]<nums[i]){
            while(i<len&&nums[i-1]<=nums[i]){
                i++;
            }
            count++;
            i--;
        }else if(nums[i-1]>nums[i]){
            while(i<len&&nums[i-1]>=nums[i]){
                i++;
            }
            count++;
            i--;
        }
    }
    return count;
}
int main(){
    vector<int> nums={1,17,5,10,13,15,10,5,16,8};
    cout<<wiggleMaxLength(nums)<<endl;
    return 0;
}
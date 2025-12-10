#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result={-1,-1};
    int index=-1;
    int begin=0;
    int end=nums.size()-1;
    while(begin<=end){
        int mid=(begin+end)/2;
        if(target==nums[mid])
        {
            if(mid==0||target>nums[mid-1]){
                result[0]=mid;
            }
            end=mid-1;
    
        }else if(target<nums[mid]){
            end=mid-1;

        }else if(target>nums[mid]){
            begin=mid+1;
        }
    }
    if(result[0]==-1)
        return result;
    begin=0;
    end=nums.size()-1;
    while(begin<=end){
        int mid=(begin+end)/2;
        if(target==nums[mid])
        {
            if(mid==nums.size()-1||target<nums[mid+1]){
                result[1]=mid;
            }
            begin=mid+1;
        }else if(target<nums[mid]){
            end=mid-1;

        }else if(target>nums[mid]){
            begin=mid+1;
        }
    }
    return result;
}
int main(){
    vector<int> nums={5,7,7,8,8,8,8,10};
    vector<int> result;
    result=searchRange(nums,8);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
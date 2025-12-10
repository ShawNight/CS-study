#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int findKthLargest(vector<int>& nums,int k){
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=0;i<nums.size();i++){
        if(Q.size()<k){
            Q.push(nums[i]);
        }
        else if(Q.top()<nums[i]){
            Q.pop();
            Q.push(nums[i]);
        }
    }
    return Q.top();
}
int main(){
    
    return 0;
}
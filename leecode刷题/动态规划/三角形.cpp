#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp;
    dp.push_back(vector<int>({triangle[0][0]}));
    for(int i=1;i<triangle.size();i++){
        dp.push_back(vector<int>(triangle[i].size(),0));
        for(int j=0;j<triangle[i].size();j++){
            if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
            else if(j==triangle[i-1].size()) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            else  dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
        }
    }
    int MIN=dp[dp.size()-1][0];
    for(int i=1;i<dp[dp.size()-1].size();i++){
        if(MIN>dp[dp.size()-1][i])
            MIN=dp[dp.size()-1][i];
    }
    return MIN;
}
int main(){
    vector<vector<int>> triangle={
        {2},{3,4},{6,5,7},{4,1,8,3}
    };
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
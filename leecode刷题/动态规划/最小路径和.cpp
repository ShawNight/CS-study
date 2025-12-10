#include<iostream>
#include<vector>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
   vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
   dp[0][0]=grid[0][0];
   for(int i=0;i<grid.size();i++){
       for(int j=0;j<grid[i].size();j++){
           if(dp[i][j]==-1){
               if(i>0 && j>0) dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
               else if(i>0) dp[i][j]=dp[i-1][j]+grid[i][j];
               else if(j>0) dp[i][j]=dp[i][j-1]+grid[i][j];
           }
       }
   }
   return dp[dp.size()-1][dp[0].size()-1];     
}
int main(){
    vector<vector<int>> grid={
        {1,3,1},{1,5,1},{4,2,1}
    };
    cout<<minPathSum(grid)<<endl;
    return 0;
}
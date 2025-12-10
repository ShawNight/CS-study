#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n=dungeon.size();
    int m=dungeon[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1]=dungeon[n-1][m-1]<1?1-dungeon[n-1][m-1]:1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 &&j==m-1) continue;
            if(i<n-1&&j<m-1){
                dp[i][j]=dungeon[i][j]-min(dp[i+1][j],dp[i][j+1]);
            }
            else if(i<n-1)  dp[i][j]=dungeon[i][j]-dp[i+1][j];
            else if(j<m-1)  dp[i][j]=dungeon[i][j]-dp[i][j+1];
            if(dp[i][j]>=1)
                dp[i][j]=1;
            else
                dp[i][j]=1-dp[i][j];
        }
    }
    
    return dp[0][0];
}
int main(){
    vector<vector<int>> dungeon={
        {-2,-3,3},{-5,-10,1},{10,30,-5}
    };
    cout<<calculateMinimumHP(dungeon);
    return 0;
}
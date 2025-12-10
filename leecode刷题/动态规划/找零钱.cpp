#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-1);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int k=0;k<coins.size();k++){
            if(i>=coins[k]&&dp[i-coins[k]]!=-1){
                if(dp[i] == -1 ||dp[i]>dp[i-coins[k]]+1)
                    dp[i]=dp[i-coins[k]]+1;
            }
        }
    }
    return dp[amount];
}
int main(){
    vector<int> coins={1, 2, 5};
    cout<<coinChange(coins,11)<<endl;
    return 0;
}
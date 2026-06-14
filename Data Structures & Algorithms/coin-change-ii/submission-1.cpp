#include<cstring>
class Solution {
public:
int dp[301][5001];
    int solve(int amount,vector<int>&coins,int n){
        if(amount==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        if(coins[n-1]<=amount){
            return dp[n][amount]=solve(amount-coins[n-1],coins,n)+solve(amount,coins,n-1);
        }
        else{
            return dp[n][amount]=solve(amount,coins,n-1);
        }
        }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        return solve(amount,coins,n);
        
    }
};

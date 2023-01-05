class Solution {
public:
    int dp[50];
    int sol(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = sol(n-1) + sol(n-2);
    }
    int climbStairs(int n) {
        for(int i=0; i<50; i++) dp[i] = -1;
        return sol(n);
    }
};
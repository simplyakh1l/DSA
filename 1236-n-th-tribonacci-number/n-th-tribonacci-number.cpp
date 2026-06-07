class Solution {
public:
    int dp[40];
    int sol(int n){
        if(n==0)return 0;
        else if(n<=2)return 1;

        if(dp[n]!=-1)return dp[n];

        return dp[n]=sol(n-1)+sol(n-2)+sol(n-3);
    }
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return sol(n);

        
    }
};
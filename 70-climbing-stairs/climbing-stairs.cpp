class Solution {
public:
    vector<int>dp;
    int sol(int n){
        if(n<=1)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];

        int s1=sol(n-1);
        int s2=sol(n-2);
        return dp[n]=s1+s2;
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);

        int ans=sol(n);
        return ans;
        
    }
};
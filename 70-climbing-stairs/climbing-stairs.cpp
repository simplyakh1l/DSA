class Solution {
public:
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);

        if(n<=1)return 1;

        int p1=1,p2=1;
        int cur;
        for(int i=2;i<=n;i++){
            cur=p1+p2;
            p2=p1;
            p1=cur;
        }
        return p1;
        
        
        
    }
};
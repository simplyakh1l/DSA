class Solution {
public:
    
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();

        vector<vector<int> >dp(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ab=(i>0)?dp[i-1][j]:INT_MAX;
                int lef=(j>0)?dp[i][j-1]:INT_MAX;
                if(i==0 && j==0)dp[i][j]=a[i][j];
                else dp[i][j]=a[i][j]+min(ab,lef);
                
            }
        }
        return dp[n-1][m-1];

        
        
    }
};
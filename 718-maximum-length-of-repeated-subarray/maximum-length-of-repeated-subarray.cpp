class Solution {
public:
    int findLength(vector<int>& a1, vector<int>& a2) {
        int n=a1.size();
        int m=a2.size();
        int t[n+1][m+1];

        for(int i=0;i<n+1;i++)t[i][0]=0;
        for(int j=0;j<m+1;j++)t[0][j]=0;

    
        int mxi=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(a1[i-1]==a2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    mxi=max(mxi,t[i][j]);
                }
                else t[i][j]=0;
            }
        }
        return mxi;
        
    }
};
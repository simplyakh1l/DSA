class Solution {
public:
    int n,m;
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        n=mat.size();
        m=mat[0].size();

        vector<vector<int> >ans(n,vector<int>(m));

        vector<vector<int> >psm(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int lsm=(j>0)?psm[i][j-1]:0;
                int absm=(i>0)?psm[i-1][j]:0;
                int csm=(i>0 && j>0)?psm[i-1][j-1]:0;
                psm[i][j]=mat[i][j]+lsm+absm-csm;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int br=(i+k)<n?i+k:n-1;
                int bc=(j+k)<m?j+k:m-1;
                int ar=(i-k)>=0?i-k:0;
                int ac=(j-k)>=0?j-k:0;

                int tsm=psm[br][bc];
                int absm=(ar>0)?psm[ar-1][bc]:0;
                int lsm=(ac>0)?psm[br][ac-1]:0;
                int csm=(ar>0 && ac>0)?psm[ar-1][ac-1]:0;
                ans[i][j]=tsm+csm-absm-lsm;
            }
        }
        return ans;



        
    }
};
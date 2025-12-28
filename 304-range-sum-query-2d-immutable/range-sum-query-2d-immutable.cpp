class NumMatrix {
public:
    vector<vector<long long> >psm;
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        psm.resize(n,vector<long long>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long absm=(i>0)?psm[i-1][j]:0;
                long long lsm=(j>0)?psm[i][j-1]:0;
                long long csm=(i>0 && j>0)?psm[i-1][j-1]:0;
                psm[i][j]=mat[i][j]+absm+lsm-csm;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        long long tsm=psm[r2][c2];
        long long absm=(r1>0)?psm[r1-1][c2]:0;
        long long lsm=(c1>0)?psm[r2][c1-1]:0;
        long long csm=(r1>0 && c1>0)?psm[r1-1][c1-1]:0;

        return tsm-absm-lsm+csm;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class Solution {
public:
    int conv(vector<int>&a){
        int n=a.size();
        int i=n-1;
        int ans=0;
        while(i>=0){
            ans+=a[i]*pow(2,n-i-1);
            i--;
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++){
            if(mat[i][0]==0){
                for(int j=0;j<m;j++)mat[i][j]=!mat[i][j];
            }
        }

        for(int j=0;j<m;j++){
            int csm=0;
            for(int i=0;i<n;i++){
                csm+=mat[i][j];
            }
            int n1=csm;
            int n0=n-csm;
            if(n0>n1){
                for(int i=0;i<n;i++){
                    mat[i][j]=!mat[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=conv(mat[i]);
        }
        return ans;


        
    }
};
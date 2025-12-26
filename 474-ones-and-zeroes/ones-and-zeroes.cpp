class Solution {
public:
    int findMaxForm(vector<string>& s, int zl, int vl) {
        int n=s.size();

        vector<int>z(n);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            int zcnt=0;
            int vcnt=0;
            for(auto it:s[i]){
                if(it=='0')zcnt++;
                else vcnt++;
            }
            z[i]=zcnt;
            v[i]=vcnt;
        }

        int t[n+1][zl+1][vl+1];

        for(int j=0;j<zl+1;j++){
            for(int k=0;k<vl+1;k++){
                t[0][j][k]=0;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=0;j<zl+1;j++){
                for(int k=0;k<vl+1;k++){
                    if(z[i-1]<=j && v[i-1]<=k){
                        int inc=1+t[i-1][j-z[i-1]][k-v[i-1]];
                        int exc=t[i-1][j][k];
                        t[i][j][k]=max(inc,exc);
                    }
                    else t[i][j][k]=t[i-1][j][k];
                }
            }
        }
        return t[n][zl][vl];
        







        
    }
};
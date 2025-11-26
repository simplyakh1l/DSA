class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int> >diff(n,vector<int>(n));

        for(auto it:q){
            int ar=it[0];
            int ac=it[1];
            int br=it[2];
            int bc=it[3];

            diff[ar][ac]++;
            if(bc+1<n)diff[ar][bc+1]--;
            if(br+1<n)diff[br+1][ac]--;
            if(br+1<n && bc+1<n)diff[br+1][bc+1]++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                diff[i][j]+=(i-1>=0)?diff[i-1][j]:0;
                diff[i][j]+=(j-1>=0)?diff[i][j-1]:0;
                diff[i][j]-=(i-1>=0 && j-1>=0)?diff[i-1][j-1]:0;
            }
        }
        return diff;

    }
};
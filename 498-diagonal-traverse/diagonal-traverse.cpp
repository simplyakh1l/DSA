class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        map<int,vector<int> >mpp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int>ans;
        for(auto it:mpp){
            if(it.first%2==0)reverse(it.second.begin(),it.second.end());
            ans.insert(ans.end(),it.second.begin(),it.second.end());
        }
        return ans;


    }
};
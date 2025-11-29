class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int> >mpp;
        vector<vector<int> >ans;

        for(int i=0;i<g.size();i++){
            mpp[g[i]].push_back(i);

            if(mpp[g[i]].size()==g[i]){
                ans.push_back(mpp[g[i]]);
                mpp[g[i]]={};
            }
        }

        return ans;


        
    }
};
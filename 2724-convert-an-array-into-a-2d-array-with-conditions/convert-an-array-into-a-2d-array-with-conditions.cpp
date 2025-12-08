class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;

        int mxi=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            mxi=max(mxi,mpp[nums[i]]);
        }

        vector<vector<int> >ans(mxi);

        for(auto it:mpp){
            int i=0;
            while(it.second--){
                ans[i].push_back(it.first);
                i++;
            }
        }
        return ans;
        
    }
};
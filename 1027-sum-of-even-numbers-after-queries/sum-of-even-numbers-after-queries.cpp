class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>ans;
        int sm=0;
        for(auto it:nums)if(it%2==0)sm+=it;

        for(auto it:q){
            int vl=it[0];
            int i=it[1];

            if(nums[i]%2==0)sm-=nums[i];
            nums[i]+=vl;
            if(nums[i]%2==0)sm+=nums[i];

            
            ans.push_back(sm);
        }
        return ans;
    }
    
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;

        int i=0,j=nums.size()-1;

        while(i<j){
            int sm=nums[i]+nums[j];
            if(sm==k){
                i++;
                j--;
                cnt++;
            }
            else if(sm<k)i++;
            else j--;
        }
        return cnt;
        
    }
};
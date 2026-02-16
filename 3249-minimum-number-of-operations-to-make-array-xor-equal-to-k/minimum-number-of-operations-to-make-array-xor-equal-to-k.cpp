class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=0;
        for(int k=0;k<22;k++){
            int cnt=0;
            for(auto it:nums){
                if((it & (1<<k))!=0)cnt++;
            }
            int xf=0;
            if((x & (1<<k))!=0)xf=1;

            if((xf==1 && cnt%2==0) || (xf==0 && cnt%2==1) ) ans++;
        }
        return ans;
        
    }
};
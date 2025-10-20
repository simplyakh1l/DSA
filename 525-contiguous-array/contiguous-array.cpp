class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>psm(n);
        int sm=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)sm--;
            else sm++;
            psm[i]=sm;
            if(sm==0)maxi=max(i+1,maxi);
        }

        
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(psm[i])==mpp.end())mpp[psm[i]]=i;
            else{
                maxi=max(i-mpp[psm[i]],maxi);
            }
        }
        return maxi;

        
    }
};
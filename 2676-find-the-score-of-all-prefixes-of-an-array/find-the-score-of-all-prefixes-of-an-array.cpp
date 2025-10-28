class Solution {
public:
    vector<long long> findPrefixScore(vector<int>&a) {
        int n=a.size();
        vector<long long>ans(n);
       
        int mxi=a[0];

        for(int i=0;i<n;i++){
            ans[i]=a[i];
            mxi=max(mxi,a[i]);
            ans[i]+=mxi;
            if(i>0)ans[i]+=ans[i-1];
        }
        return ans;
        
    }
};
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        long long sm=0;
        int ans=0;
        unordered_map<long long,int>mpp;
        mpp[0]++;
        for(int i=0;i<n;i++){
            sm+=a[i];
            long long rem=sm-k;
            ans+=mpp[rem];
            mpp[sm]++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int>ans(n);
        unordered_map<int,int>mpp;
        int cnt=0;
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
            mpp[b[i]]++;
            if(mpp[a[i]]==2)cnt++;
            if(mpp[b[i]]==2 && b[i]!=a[i])cnt++;
            ans[i]=cnt;
            
        }
        return ans;
    }
};
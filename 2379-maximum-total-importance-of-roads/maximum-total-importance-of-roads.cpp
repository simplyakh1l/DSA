class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& edges) {
        vector<int>d(n);
        for(auto it:edges){
            d[it[0]]++;
            d[it[1]]++;
        }
        long long ans=0;
        sort(d.begin(),d.end());
        int ci=n;
        for(int i=n-1;i>=0;i--){
            ans+=(1LL*ci*d[i]);
            ci--;
        }
        return ans;



        
    }
};
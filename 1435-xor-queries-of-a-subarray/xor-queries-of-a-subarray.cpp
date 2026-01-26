class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size();
        vector<long long>pre(n);
        pre[0]=a[0];

        vector<int>ans;

        for(int i=1;i<n;i++)pre[i]=pre[i-1]^a[i];

        for(auto it:q){
            int l=it[0];
            int r=it[1];
            int tmp;
            tmp=pre[r]^((l>0)?pre[l-1]:0);
            ans.push_back(tmp);
        }
        return ans;
        
        
    }
};
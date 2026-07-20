class Solution {
public:
    long long dfs(int nde,vector<vector<int> >&adj,vector<int>&a){
        if(adj[nde].empty()){
            return 1LL*a[nde];
        }

        long long earl=LLONG_MAX,lat=0;
        for(auto it:adj[nde]){
            long long val=dfs(it,adj,a);
            earl=min(val,earl); lat=max(lat,val);
        }

        long long od=(lat-earl)+a[nde];
        return lat+od;

    }
    long long finishTime(int n, vector<vector<int>>& ed, vector<int>& a) {
        vector<vector<int> >adj(n);
        for(auto it:ed){
            adj[it[0]].push_back(it[1]);
        }

        long long ans=dfs(0,adj,a);
        return ans;
        
    }
};
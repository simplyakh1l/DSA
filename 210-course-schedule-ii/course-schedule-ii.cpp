class Solution {
public:
    void dfs(int nde,vector<vector<int> >&adj,vector<int>&vis,vector<int>&ans,int &f){
        vis[nde]=1;
        for(auto it:adj[nde]){
            if(vis[it]==0)dfs(it,adj,vis,ans,f);
            else if(vis[it]==1){
                f=1;
            }
            
        }
        vis[nde]=2;
        ans.push_back(nde);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<vector<int> >adj(n);
        vector<int>ans,vis(n);
        for(auto it:edge){
            adj[it[1]].push_back(it[0]);
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,ans,f);
            }
        }
        if(f)return {};
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};
class Solution {
public:
    void dfs(int nde,vector<vector<int> >&adj,vector<int>&vis,int cnt,int &f){
        vis[nde]=cnt+1;
        for(auto it:adj[nde]){
            if(vis[it]==0)dfs(it,adj,vis,cnt+1,f);
            else{
                int diff=abs(vis[it]-vis[nde]+1);
                if(diff%2)f=1;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n);

        int cnt=0;
        int f=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int cnt=0;
                dfs(i,adj,vis,cnt,f);
                if(f)return false;
            }
        }
        
        return true;

    }
};
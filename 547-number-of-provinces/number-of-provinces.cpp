class Solution {
public:
    void dfs(int nde,vector<vector<int> >&adj,vector<int>&vis){
        if(vis[nde]==1)return;

        vis[nde]=1;

        for(auto it:adj[nde]){
            dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& amat) {
        int n=amat.size();
        vector<vector<int> >adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(amat[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;

        
    }
};
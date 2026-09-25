class Solution {
public:
    void bfs(vector<int>&vis,vector<vector<int> >&adj,int k){
        queue<int>q;
        vis[k]=1;
        q.push(k);

        while(q.size()){
            int nde=q.front(); q.pop();
            for(auto it:adj[nde]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    void dfs(int nde,vector<int>&vis,vector<vector<int> >&adj,int &f){
        vis[nde]=2;
        if(f)return;

        for(auto it:adj[nde]){
            if(vis[it]==1)f=1;
            if(vis[it]==0)dfs(it,vis,adj,f);
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int> >adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>vis(n);
        bfs(vis,adj,k);
        int f=0;
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,f);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(f){
                ans.push_back(i);
            }
            else{
                if(vis[i]!=1)ans.push_back(i);
            }
        }
        return ans;
        

        

        

        
    }
};
class Solution {
public:
    int non(int rt,vector<vector<int> >&adj){
        int n=adj.size();
        vector<int>vis(n);
        queue<int>q;
        q.push(rt);
        vis[rt]=1;
        int cnt=1;

        while(q.size()){
            int nde=q.front();
            q.pop();

            for(auto it:adj[nde]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool bfs(int rt,vector<vector<int> >&adj,vector<int> &vis,int tn){
        queue<int>q;
        q.push(rt);
        vis[rt]=1;
        int f=1;

        while(q.size()){
            int nde=q.front();
            q.pop();

            for(auto it:adj[nde]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                }
                if(adj[it].size()!=tn-1)f=0;
            }
        }
        return f;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int> >adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int tn=non(i,adj);
                bool chck=bfs(i,adj,vis,tn);
                if(chck)ans++;
            }
        }
        return ans;
    }
};
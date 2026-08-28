class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<vector<int> >adj(n);
        vector<int>deg(n);
        for(auto it:edge){
            adj[it[1]].push_back(it[0]);
            deg[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);
        vector<int>ans;
        while(q.size()){
            int nde=q.front();
            ans.push_back(nde);
            q.pop();

            for(auto it:adj[nde]){
                deg[it]--;
                if(deg[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n)return true;
        return false;





        
    }
};
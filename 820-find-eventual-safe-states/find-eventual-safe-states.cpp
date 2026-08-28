class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int> >adj(n);
        vector<int>deg(n);
        for(int i=0;i<n;i++){
            for(auto it:a[i]){
                adj[it].push_back(i);
                deg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);

        vector<int>ans;
        while(q.size()){
            int nde=q.front(); q.pop();
            ans.push_back(nde);

            for(auto it:adj[nde]){
                deg[it]--;
                if(deg[it]==0)q.push(it);
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;


        
    }
};
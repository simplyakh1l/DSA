class Solution {
public:
    void sol(set<int>&st,vector<vector<vector<int> > >adj){
        queue<int>q;
        q.push(1);
        st.insert(1);

        while(q.size()){
            int nde=q.front();
            q.pop();

            for(auto it:adj[nde]){
                if(st.find(it[0])==st.end()){
                    q.push(it[0]);
                    st.insert(it[0]);
                }
            }
        }
    }
    
    
    int minScore(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int> > >adj(n+1);
        set<int>st;

        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        sol(st,adj);

        int ans=INT_MAX;
        for(auto it:edges){
            if(st.find(it[0])!=st.end()){
                ans=min(ans,it[2]);
            }
        }
        return ans;
        
        
    }
};
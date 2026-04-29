class Solution {
public:

    void sol(int nde,vector<int>&ans,map<int,vector<int> > &mpp,set<int>&vis){
        ans.push_back(nde);
        vis.insert(nde);

        for(auto it:mpp[nde]){
            if(vis.find(it)==vis.end()){
                sol(it,ans,mpp,vis);
            }
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,vector<int> >mpp;
        for(auto it:a){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }

        int st;
        for(auto it:mpp){
            if(it.second.size()==1){
                st=it.first;
                break;
            }
        }
        vector<int>ans;
        set<int>vis;
        
        sol(st,ans,mpp,vis);
        return ans;
        

       


        
    }
};
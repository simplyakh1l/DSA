class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n=p.size();
        int m=t.size();

        sort(p.begin(),p.end());
        multiset<int>st;
        for(auto it:t)st.insert(it);
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty())return ans;
            else{
                auto lb=st.lower_bound(p[i]);
                if(lb==st.end())return ans;
                else{
                    st.erase(lb);
                    ans++;
                }
            }
        }
        return ans;

        
    }
};
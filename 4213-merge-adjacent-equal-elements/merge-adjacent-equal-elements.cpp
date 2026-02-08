class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& a) {
        int n=a.size();
        vector<long long>ans;

        for(int i=0;i<n;i++){
            if(ans.empty() || a[i]!=ans.back())ans.push_back(a[i]);
            else{
                ans.push_back(a[i]);
                
                while(ans.size()>1 && ans[ans.size()-1]==ans[ans.size()-2]){
                    int len=ans.size();
                    long long e1=ans[len-1];
                    long long e2=ans[len-2];
                    ans.pop_back(); ans.pop_back();
                    ans.push_back(e1+e2);
                }
            }
        }
        return ans;
        
        
    }
};
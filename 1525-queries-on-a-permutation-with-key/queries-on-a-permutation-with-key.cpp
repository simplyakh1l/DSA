class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int>ans;
        vector<int>a; for(int i=0;i<m;i++)a.push_back(i+1);

        for(auto it:q){
            for(int i=0;i<m;i++){
                if(a[i]==it){
                    ans.push_back(i);
                    a.erase(a.begin()+i);
                    a.insert(a.begin(),it);
                }
            }

        }
        return ans;
    }
};
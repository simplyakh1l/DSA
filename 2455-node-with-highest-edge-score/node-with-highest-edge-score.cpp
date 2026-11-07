class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        map<int,long long>mpp;
        for(int i=0;i<n;i++){
            mpp[edges[i]]+=i;
        }

        long long maxi=0;
        int mel=0;
        for(auto it:mpp){
            if(it.second>maxi){
                maxi=it.second;
                mel=it.first;
            }
        }
        return mel;
        
    }
};
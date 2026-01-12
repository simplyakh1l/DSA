class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>a(2052);

        for(auto it:logs){
            a[it[0]]++;
            a[it[1]]--;
        }
        for(int i=1;i<2052;i++)a[i]+=a[i-1];

        int ans=0;
        int maxi=0;
        for(int i=0;i<2052;i++){
            if(a[i]>maxi){
                maxi=a[i];
                ans=i;
            }
        }
        
        return ans;
        
    }
};
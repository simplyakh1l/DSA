class Solution {
public:
    int minimumPrefixLength(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int fi=-1,li=-1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1])continue;
            else{
                ans=i;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int minAbsoluteDifference(vector<int>& a) {
        int n=a.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]==1 && a[j]==2){
                    ans=min(ans,abs(j-i));
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};
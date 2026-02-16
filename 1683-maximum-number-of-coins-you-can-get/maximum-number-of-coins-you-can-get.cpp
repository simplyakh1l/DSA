class Solution {
public:
    int maxCoins(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int i=0,j=n-2;
        int ans=0;
        for(int x=0;x<n/3;x++){
            ans+=a[j];
            j-=2;
        }
        return ans;
        
    }
};
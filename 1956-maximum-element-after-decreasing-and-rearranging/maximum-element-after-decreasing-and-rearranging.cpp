class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        
        int ans=1;
        a[0]=1;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>=1){
                a[i]=a[i-1]+1;
            }
        }
        return a[n-1];
    }
};
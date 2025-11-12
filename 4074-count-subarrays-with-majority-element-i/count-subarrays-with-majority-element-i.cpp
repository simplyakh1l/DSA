class Solution {
public:
    int countMajoritySubarrays(vector<int>&a, int t) {
        int n=a.size();

        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(a[j]==t)cnt++;
                if(cnt>(j-i+1)/2)ans++;
            }
        }
        return ans;
        
    }
};
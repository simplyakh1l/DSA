class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        sort(a.begin(),a.end(),greater<int>());
        int n=a.size();

        int cnt=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(a[i]-cnt<0)break;
            ans+=(a[i]-cnt);
            cnt++;
            if(cnt==k)break;
        }
        return ans;
        
    }
};
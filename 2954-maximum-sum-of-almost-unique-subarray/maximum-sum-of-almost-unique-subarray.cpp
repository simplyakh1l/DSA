class Solution {
public:
    long long maxSum(vector<int>& a, int m, int k) {
        int n=a.size();
        int i=0,j=0;
        map<int,int>mpp;
        long long sm=0;
        long long ans=0;
        while(j<n){
            mpp[a[j]]++;
            sm+=a[j];
            if(j-i+1<k)j++;
            else{
                if(mpp.size()>=m){
                    ans=max(ans,sm);
                }
                mpp[a[i]]--;
                if(mpp[a[i]]==0)mpp.erase(a[i]);
                sm-=a[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
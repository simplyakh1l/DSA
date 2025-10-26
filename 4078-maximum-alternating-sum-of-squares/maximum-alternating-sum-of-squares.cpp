class Solution {
public:
    long long maxAlternatingSum(vector<int>&a) {
        int n=a.size();
        for(int i=0;i<n;i++)a[i]=abs(a[i]);
        sort(a.begin(),a.end());
        int i=0,j=n-1;
        long long ans=0;
        for(int k=0;k<n;k++){
            if(k%2==0){
                ans+=(long long)((long long)a[j]*a[j]);
                j--;
            }
            else{
                ans-=(long long)((long long)a[i]*a[i]);
                i++;
            }
        }
        return ans;
    }
};
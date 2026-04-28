class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n=a.size();

        int i=0;
        int j;
        long long ans=0;

        while(i<n){
            j=i+1;
            while(j<n && a[j]-a[j-1]==-1)j++;
            long long len=(j-i);
            ans+=(len*(len+1))/2;
            i=j;
        }
        long long len=(j-i);
        ans+=(len*(len+1))/2;

        return ans;
        
    }
};
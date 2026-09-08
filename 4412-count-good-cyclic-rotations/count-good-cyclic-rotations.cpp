class Solution {
public:
    int countGoodRotations(vector<int>& a) {
        int n=a.size();
        long long rsm=accumulate(a.begin(),a.end(),0LL);
        long long lsm=0;
        for(int i=0;i<(n/2);i++)lsm+=a[i];
        rsm-=lsm;


        int ans=0;

        for(int i=0;i<n;i++){
            if(lsm>rsm)ans++;
            lsm-=a[i];
            rsm+=a[i];
            lsm+=a[(i+(n/2))%n];
            rsm-=a[(i+(n/2))%n];
        }
        
        return ans;
        
    }
};
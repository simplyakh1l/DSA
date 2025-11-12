class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& a) {
        int n=a.size();
        vector<int>psm(n);
        vector<int>ssm(n);

        psm[0]=a[0];
        ssm[n-1]=a[n-1];

        for(int i=1;i<n;i++){
            psm[i]=psm[i-1]+a[i];
            ssm[n-i-1]=ssm[n-i]+a[n-i-1];
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int lsm=(i>0)?psm[i-1]:0;
            int rsm=(i<n-1)?ssm[i+1]:0;

            ans[i]=((i*a[i])-lsm)+(rsm-((n-i-1)*a[i]));
        }
        return ans;
        
    }
};
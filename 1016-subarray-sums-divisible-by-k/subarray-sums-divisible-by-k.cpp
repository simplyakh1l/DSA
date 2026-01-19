class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size();

        vector<int>psm(n);
        psm[0]=(a[0]%k+k)%k;
        
        for(int i=1;i<n;i++){
            psm[i]=a[i]+psm[i-1];
            psm[i]=(psm[i]%k+k)%k;
        }

        int ans=0;

        map<int,int>mpp;
        mpp[0]++;
        for(int i=0;i<n;i++){
            if(mpp.find(psm[i])!=mpp.end()){
                ans+=mpp[psm[i]];
            }
            mpp[psm[i]]++;
        }
        return ans;
        
        
    }
};
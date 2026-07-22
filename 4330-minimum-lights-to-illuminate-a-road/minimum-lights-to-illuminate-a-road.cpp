class Solution {
public:
    int minLights(vector<int>& a) {
        int n=a.size();
        vector<int>ill(n);

        int uc=0;
        for(int i=0;i<n;i++){
            if(uc>0){
                ill[i]=1; uc--;
            }
            if(a[i]>0){
                uc=max(uc,a[i]);
                ill[i]=1;
            }
            
        }
        uc=0;
        for(int i=n-1;i>=0;i--){
            if(uc>0){
                ill[i]=1; uc--;
            }
            if(a[i]>0){
                ill[i]=1;
                uc=max(a[i],uc);
            }
        }

        
        int i=0,j;
        int ans=0;
        while(i<n){
            if(ill[i]==1)i++;
            else{
                j=i;
                while(j<n && ill[j]==0)j++;
                int len=j-i;
                ans+=ceil(1.0*len/3);
                i=j;
            }
        }
        return ans;

        
    }
};
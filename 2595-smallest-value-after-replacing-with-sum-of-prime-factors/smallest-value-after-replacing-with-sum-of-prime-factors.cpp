class Solution {
public:
    int sol(int n){
        int sm=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    sm+=i;
                    n/=i;
                }
            }
        }
        if(n>1)sm+=n;
        return sm;
    }
    
    int smallestValue(int n) {
        int t2=n;
        int ans=INT_MAX;
        int t1=sol(n);
        ans=min(t1,ans);
        while(t1!=t2){
            t2=t1;
            t1=sol(t1);
            ans=min(t1,ans);
        }
        return ans;
        
        
    }
};
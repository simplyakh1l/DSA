class Solution {
public:
     long long sol(int c1, int c2, int c3, int N1, int N2) {
        long long ans=0;
         long long n1=N1;
         long long n2=N2;
         if(c3<=c1 && c3<=c2){
             return c3*max(n1,n2);
         }
        else if(c3<=c1){
            ans+=(c3*n1);
            n2-=n1;
            n1=0; 
        }
        else if(c3<=c2){
            ans+=(c3*n2);
            n1-=n2;
            n2=0;
        }
        else if(c3>c1 && c3>c2){
            if(c3<=c1+c2){
                int mini=min(n1,n2);
                ans+=(long long)c3*mini;
                n1-=mini;
                n2-=mini;
            }
        }
        if(n1>0)ans+=(c1*n1);
        if(n2>0)ans+=(c2*n2); 
        
        return ans;
    }
    long long minimumCost(int c1, int c2, int c3, int N1, int N2) {
        long long a1=sol(c1,c2,c3,N1,N2);
        long long a2=sol(c2,c1,c3,N2,N1);
        return min(a1,a2);
        
        
    }
};
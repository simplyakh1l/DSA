class Solution {
public:
    void sol(set<int>&st,int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                st.insert(i);
                while(n%i==0){
                    n/=i;
                }
            }
        }
        if(n!=1)st.insert(n);
    }
    int distinctPrimeFactors(vector<int>& a) {
        int n=a.size();
        set<int>st;
        
        for(int i=0;i<n;i++){
            sol(st,a[i]);
        }
        return st.size();

        
    }
};
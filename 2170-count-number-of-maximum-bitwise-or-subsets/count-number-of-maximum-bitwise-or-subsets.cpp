class Solution {
public:
    void sol(int i,int &n,vector<int>&a,int cval,int &maxi,int &ans){
        if(i>=n){
            if(cval>maxi){
                maxi=cval;
                ans=1;
            }
            else if(cval==maxi){
                ans++;
            }
            return;
        }

        sol(i+1,n,a,(cval | a[i]),maxi,ans);
        sol(i+1,n,a,cval,maxi,ans);
        return;
    }

    int countMaxOrSubsets(vector<int>& a) {
        int n=a.size();
        int maxi=INT_MIN;
        int ans=0;
        sol(0,n,a,0,maxi,ans);

        return ans;
    }
};
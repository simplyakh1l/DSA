class Solution {
public:
    bool chck(vector<int>&a){
        int n=a.size();
        int d=a[1]-a[0];
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]!=d)return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
            if(r[i]-l[i]+1<2){
                ans[i]=false;
                continue;
            }
            vector<int>tmp(a.begin()+l[i],a.begin()+r[i]+1);
            sort(tmp.begin(),tmp.end());

            if(chck(tmp))ans[i]=true;
            else ans[i]=false;
        }
        return ans;
        
        
        
    }
};
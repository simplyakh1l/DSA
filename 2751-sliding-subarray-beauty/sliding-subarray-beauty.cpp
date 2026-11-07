class Solution {
public:
    int sol(map<int,int>&mpp,int x){
        for(auto it:mpp){
            if(it.second>=x){
                return it.first;
            }
            x-=it.second;
        }
        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& a, int k, int x) {
        int n=a.size();
        int i=0,j=0;
        vector<int>ans;map<int,int>mpp;

        while(j<n){
            if(a[j]<0)mpp[a[j]]++;
            if(j-i+1<k)j++;

            else{
                ans.push_back(sol(mpp,x));
                if(a[i]<0)mpp[a[i]]--;
                if(mpp[a[i]]==0)mpp.erase(a[i]);
                i++; j++;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int sol(vector<int>a){
        int n=a.size();
        int ans=INT_MAX;
        int i=0;
        int k=2;
        while(k<n){
            int j=i+1;
            int sm=abs(a[i]-a[j])+abs(a[j]-a[k])+abs(a[i]-a[k]);
            ans=min(ans,sm);
            i++;
            k++;
        }
        return ans;
    }
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int> >mpp;
        int n=nums.size();

        for(int i=0;i<n;i++)mpp[nums[i]].push_back(i);

        int ans=INT_MAX;
        for(auto it:mpp){
            if(it.second.size()<3)continue;
            else{
                ans=min(ans,sol(it.second));
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;

        
    }
};
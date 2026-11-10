class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<long long>st;
        for(auto it:nums)st.insert(it);

        int ans=0;
        for(long long it:nums){
            if(st.find(1LL*it*it)!=st.end()){
                int cnt=1;
                while(st.find(1LL*it*it)!=st.end()){
                    st.insert(it);
                    it*=it;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        if(ans==0)return -1;
        return ans;

        
    }
};
class FindSumPairs {
public:
    vector<int>a1,a2;
    unordered_map<int,int>m1,m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a1=nums1;
        a2=nums2;
        for(auto it:a1)m1[it]++;
        for(auto it:a2)m2[it]++;
    }
    
    void add(int index, int val) {
        m2[a2[index]]--;
        a2[index]+=val;
        m2[a2[index]]++;    
    }
    
    int count(int t) {
        int ans=0;
        for(auto it:m1){
            int rem=(t-it.first);
            ans+=(m2[rem]*it.second);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>mpp;
        map<int,set<int> >mpp2;
        for(auto it:nums)mpp[it]++;
        for(auto it:mpp){
            mpp2[it.second].insert(it.first);
        }
      
        for(auto it:nums){
            int freq=mpp[it];
            if(mpp2[freq].size()==1){
                return it;
            }
        }
        return -1;

    }
};
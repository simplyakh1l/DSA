class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int f=0;
        int i=0;
        int li=-1;

        while(i<nums.size()){
            if(nums[i]==1){
                if(i-li-1<k && li!=-1)return false;
                li=i;
            }
            i++;
        }
        return true;
    }
};
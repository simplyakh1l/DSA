class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& r, int adi) {
        int n=cap.size();
        vector<long long>rem(n);
        for(int i=0;i<n;i++){
            rem[i]=cap[i]-r[i];
        }

        sort(rem.begin(),rem.end());

        int ans=0;
        // 0 0 0 1-> 0-> 3
        for(int i=0;i<n;i++){
            if(adi>0 && adi>=rem[i]){
                adi-=rem[i];
                rem[i]=0;
                ans++;
            }
        }
        return ans;

    }
};
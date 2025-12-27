class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();

        int mxe1=INT_MIN;
        int mxi1=-1;
        int mne1=INT_MAX;
        int mni1=-1;
        for(int i=0;i<n;i++){
            if(a[i][0]<mne1){
                mne1=a[i][0];
                mni1=i;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i][a[i].size()-1]>mxe1 && i!=mni1){
                mxe1=a[i][a[i].size()-1];
                mxi1=i;
            }
        }
        int mxe2=INT_MIN;
        int mxi2=-1;
        int mne2=INT_MAX;
        int mni2=-1;
        for(int i=0;i<n;i++){
            if(a[i][a[i].size()-1]>mxe2){
                mxe2=a[i][a[i].size()-1];
                mxi2=i;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i][0]<mne2 && i!=mxi2){
                mne2=a[i][0];
                mni2=i;
            }
        }
        
        
        int a1=mxe1-mne1;
        int a2=mxe2-mne2;
        return max(a1,a2);




        
    }
};
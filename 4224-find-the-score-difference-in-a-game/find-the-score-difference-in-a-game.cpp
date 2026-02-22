class Solution {
public:
    int scoreDifference(vector<int>& a) {
        int p1=0;
        int p2=0;
        int n=a.size();
        char c=1;
        for(int i=0;i<n;i++){
            if(a[i]%2==1){
                c=!c;
            }
            if((i+1)%6==0){
                c=!c;
            }
            if(c){
                p1+=a[i];
            }
            else{
                p2+=a[i];
            }
        }
        return p1-p2;
        
    }
};
class Solution {
public:
    vector<int> rotateElements(vector<int>& a, int k) {
        int n=a.size();
        vector<int>vis(n);
        vector<int>tmp;
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                tmp.push_back(a[i]);
                vis[i]=1;
            }
        }
        int m=tmp.size();
        if(m==0)return a;
        k%=m;
        rotate(tmp.begin(),tmp.begin()+k,tmp.end());

        int j=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                a[i]=tmp[j];
                j++;
            }
        }
        return a;
        
    }
};
class Solution {
public:
    bool isv(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;
    }

    void rev(string &s,int l,int r){
        int i=l;
        int j=r;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int n=s.size();
        int t=0;
        int i=0;
        for(;i<n;i++){
            if(s[i]==' '){
                i++;
                break;
            }
            if(isv(s[i]))t++;
        }

        int cnt=0;
        int j=i;
        while(i<n){
            if(isv(s[i]))cnt++;
            else if(s[i]==' '){
                if(cnt==t)rev(s,j,i-1);
                j=i+1;
                cnt=0;
            }
            i++;
        }
        if(cnt==t)rev(s,j,i-1);
        return s;
        
    }
};
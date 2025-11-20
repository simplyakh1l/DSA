class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        int n=t.size();

        vector<string>ans;
        vector<int>time(n);
        vector<int>amt(n);
        vector<string>name(n),city(n);

        for(int i=0;i<n;i++){
            stringstream ss(t[i]);
            string tm,at;
            getline(ss,name[i],',');
            getline(ss,tm,',');
            getline(ss,at,',');
            getline(ss,city[i],',');

            amt[i]=stoi(at);
            time[i]=stoi(tm);
        }


        for(int i=0;i<n;i++){
            if(amt[i]>1000)ans.push_back(t[i]);
            else{
                for(int j=0;j<n;j++){
                    if(j!=i && city[j]!=city[i] && name[i]==name[j] && abs(time[i]-time[j])<=60){
                        ans.push_back(t[i]);
                        break;
                    }
                }
            }
        }
        return ans;
        

        
    }

};
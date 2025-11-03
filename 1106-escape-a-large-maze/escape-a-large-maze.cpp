class Solution {
public:
    void poss(vector<int> &s,vector<int>&t,set<pair<int,int> >&bl,int &f){
        queue<pair<int,int> >q;
        set<pair<int,int> >st;

        st.insert({s[0],s[1]});
        q.push({s[0],s[1]});

        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};

        int area=0;

        while(q.size()){
            pair<int,int>tmp=q.front();
            q.pop();

            if(f)break;

            int cr=tmp.first;
            int cc=tmp.second;

            area++;
            if(area>=4e4)f=1;

            if(cr==t[0] && cc==t[1])f=1;

            for(int i=0;i<4;i++){
                int nr=cr+row[i];
                int nc=cc+col[i];

                if(nr>=0 && nc>=0 && nr<1e6 && nc<1e6 && st.find({nr,nc})==st.end() && bl.find({nr,nc})==bl.end()){
                    q.push({nr,nc});
                    st.insert({nr,nc});
                }
            }
        }
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
        set<pair<int,int> >bl;
        for(auto it : blocked)bl.insert({it[0],it[1]});

        int sf=0,tf=0;
        poss(s,t,bl,sf);
        poss(t,s,bl,tf);

        if(sf && tf)return 1;
        return 0;
    }
};
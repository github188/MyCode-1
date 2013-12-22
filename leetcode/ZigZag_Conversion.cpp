/*
Just work at it said.
*/
class Solution {
public:
    string convert(string s, int nRows) {
        string Ans="";
        if (nRows<2) return s;
        vector<string> SetS;SetS.clear();
        for (int i=0;i<nRows;i++) SetS.push_back(Ans);
        int n=s.length();
        int x=0,y=-1;
        for (int i=0;i<n;i++)
        {
            SetS[x]+=s[i];
            if ((x==0)&&(y==-1)) y=1;
            if ((x==nRows-1)&&(y==1)) y=-1;
            x+=y;
        }
        for (int i=0;i<nRows;i++) Ans+=SetS[i];
        return Ans;
    }
};

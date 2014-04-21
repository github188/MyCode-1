class Solution {
public:
    void reverseWords(string &s) {
        int len=s.length();
        vector<string> ans;
        ans.clear();
        int h=len-1;
        while (h>=0)
        {
            while ((h>=0)&&(s[h]==' ')) h--;
            if (h<0) break;
            int t=h;
            while ((t>=0)&&(s[t]!=' ')) t--;
            if (t+1<=h) t++;
            string temp="";
            for (int i=t;i<=h;i++) temp+=s[i];
            ans.push_back(temp);
            h=t-1;
        }
        s="";
        for (int i=0;i<ans.size();i++)
        {
            s+=ans[i];
            if (i!=ans.size()-1) s+=" ";
        }
    }
};
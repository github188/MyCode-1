/*
The shortest path.
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int n=start.length();
        vector<string> *cur=new vector<string>();cur->clear();
        cur->push_back(start);
        if (start==end) return 1;
        int step=1;
        while (cur->size()>0)
        {
            step++;
            vector<string> *next=new vector<string>();next->clear();
            int m=cur->size();
            for (int i=0;i<m;i++)
            {
                string tmp=(*cur)[i];
                for (int j=0;j<n;j++)
                    for (int k=0;k<26;k++)
                    {
                        string tmp1=tmp;
                        tmp1[j]=(char)('a'+k);
                        if (tmp1==end) return step;
                        if (dict.find(tmp1)!=dict.end())
                        {
                            next->push_back(tmp1);
                            dict.erase(tmp1);
                        }
                    }
            }
            delete cur;
            cur=next;
        }
        return 0;
    }
};

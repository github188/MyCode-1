/*
Dynamic Programming.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length();
        if (n+m!=s3.length()) return false;
        set<int> hash;
        hash.clear();
        hash.insert(0);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                if (i+j>0)
                {
                    if ((i>0)&&(hash.find(i*m+i-m-1+j)!=hash.end())&&(s1[i-1]==s3[i+j-1]))
                    {
                        hash.insert(i*m+i+j);
                        continue;
                    }
                    if ((j>0)&&(hash.find(i*m+i-1+j)!=hash.end())&&(s2[j-1]==s3[i+j-1])) hash.insert(i*m+i+j);
                }
        return (hash.find(n*m+n+m)!=hash.end());
    }
};
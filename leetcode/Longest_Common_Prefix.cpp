/*
Loop and deal it.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;ans.clear();
        int n=strs.size();
        if (n==0) return ans;
        if (n==1) return strs[0];
        int m=strs[0].length();
        for (int i=1;i<n;i++) m=(m<strs[i].length()?m:strs[i].length());
        for (int j=0;j<m;j++)
        {
            bool sucess=true;
            for (int i=1;i<n;i++)
            if (strs[i][j]!=strs[0][j]) {sucess=false;break;}
            if (sucess) ans+=strs[0][j]; else return ans;
        }
        return ans;
    }
};
/*
String Match. The symbol '*' means the chars which is the same as the first one.
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ((p[0]==0)&&(s[0]!=0)) return false;
        if (s[0]=='\0')
        {
            while (p[0]!=0)
            {
                if (p[1]=='*') p+=2; else return false;
            }
            if (p[0]=='\0') return true;
            return false;
        }
        if ((s[0]==p[0])||(p[0]=='.'))
        {
            if (p[1]!='*') return isMatch(s+1,p+1);
            else
            {
                const char* f=s;
                while ((f[0]!=0)&&((s[0]==f[0])||(p[0]=='.')))
                {
                    f++;
                    bool tmp=isMatch(f,p+2);
                    if (tmp) return true;
                }
                return isMatch(s,p+2);
            }
        }
        if (p[1]=='*') return isMatch(s,p+2);
        else return false;
    }
};
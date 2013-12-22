class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length(),m=b.length();
        while (n<m) {a="0"+a;n++;}
        while (n>m) {b="0"+b;m++;}
        string Ans="";int plus=0;
        for (int i=m-1;i>=0;i--)
        {
            int x=a[i]-'0',y=b[i]-'0';
            x+=y+plus;
            if (x>1) {plus=1;x-=2;} else plus=0;
            Ans=(char)(x+'0')+Ans;
        }
        if (plus) Ans="1"+Ans;
        return Ans;
    }
};

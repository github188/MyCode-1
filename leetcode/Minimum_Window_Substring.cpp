class Solution {
public:
    string minWindow(string S, string T) {
        int n=S.length(),m=T.length();
        string Ans="";
        if ((n==0)||(n<m)||(m==0)) return Ans;
        int a[300],b[300];
        for (int i=0;i<300;i++) a[i]=b[i]=0;
        for (int i=0;i<m;i++) a[T[i]]++;
        int ansl,ansr,l,r;
        ansl=ansr=-1;l=r=0;
        int higher=0;
        for (int i=0;i<300;i++) if (a[i]>0) higher++;
        for (r=0;r<n;r++)
        {
            b[S[r]]++;
            if ((a[S[r]]>0)&&(a[S[r]]==b[S[r]])) higher--;
            if (higher==0) break;
        }
        if (higher>0) return Ans;
        while (a[S[l]]<b[S[l]]) b[S[l++]]--;
        ansl=l;ansr=r;
        for (int i=r+1;i<n;i++)
        {
            b[S[i]]++;
            while (a[S[l]]<b[S[l]]) b[S[l++]]--;
            if (i-l<ansr-ansl) ansl=l,ansr=i;
        }
        if (ansl<-1) return Ans;
        for (int i=ansl;i<=ansr;i++) Ans+=S[i];
        return Ans;
    }
};
